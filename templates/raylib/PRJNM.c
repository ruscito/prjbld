/* PRJNM.c*/ 
#include "PRJNM.h"

#include "raylib.h"
#include "raymath.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define MOVE_SPEED 10.0f
#define CAMERA_OFFSET 15.0f

typedef struct {
    Vector3 position;
    Vector3 target;
    bool isMoving;
    BoundingBox bounds;
} Player;

typedef struct {
    Camera3D camera;
    float cameraAngle;
} GameCamera;

// Initialize player
Player InitPlayer(void) {
    Player player = {0};
    player.position = (Vector3){ 0.0f, 1.0f, 0.0f };
    player.target = player.position;
    player.isMoving = false;
    player.bounds = (BoundingBox){
        (Vector3){ -0.5f, 0.0f, -0.5f },
        (Vector3){ 0.5f, 2.0f, 0.5f }
    };
    return player;
}

// Initialize isometric camera
GameCamera InitCamera(void) {
    GameCamera gameCamera = {0};
    gameCamera.camera.position = (Vector3){ 10.0f, 10.0f, 10.0f };
    gameCamera.camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    gameCamera.camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    gameCamera.camera.fovy = 45.0f;
    gameCamera.camera.projection = CAMERA_PERSPECTIVE;
    gameCamera.cameraAngle = 45.0f;
    return gameCamera;
}

// Get world position from screen coordinates
Vector3 GetWorldPosition(Ray ray, float groundY) {
    Vector3 groundPosition = {0};
    Ray groundRay = ray;
    Vector3 groundNormal = { 0.0f, 1.0f, 0.0f };
    Vector3 groundPoint = { 0.0f, groundY, 0.0f };
    
    // Calculate intersection with ground plane
    float t = (Vector3DotProduct(Vector3Subtract(groundPoint, groundRay.position), groundNormal)) /
              (Vector3DotProduct(groundRay.direction, groundNormal));
              
    groundPosition = Vector3Add(groundRay.position, Vector3Scale(groundRay.direction, t));
    return groundPosition;
}

// Update camera position based on player position
void UpdateGameCamera(GameCamera *gameCamera, Player *player) {
    float offsetDistance = CAMERA_OFFSET;
    Vector3 cameraOffset = {
        cosf(gameCamera->cameraAngle * DEG2RAD) * offsetDistance,
        offsetDistance,
        sinf(gameCamera->cameraAngle * DEG2RAD) * offsetDistance
    };
    
    gameCamera->camera.position = Vector3Add(player->position, cameraOffset);
    gameCamera->camera.target = player->position;
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Isometric 3D Game");
    SetTargetFPS(60);

    Player player = InitPlayer();
    GameCamera gameCamera = InitCamera();
    
    // Game grid for visual reference
    const int gridSize = 20;
    
    while (!WindowShouldClose()) {
        // Update player movement
        if (player.isMoving) {
            Vector3 direction = Vector3Subtract(player.target, player.position);
            float distance = Vector3Length(direction);
            
            if (distance > 0.1f) {
                direction = Vector3Scale(Vector3Normalize(direction), MOVE_SPEED * GetFrameTime());
                player.position = Vector3Add(player.position, direction);
            } else {
                player.isMoving = false;
            }
        }
        
        // Handle mouse input
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Ray ray = GetMouseRay(GetMousePosition(), gameCamera.camera);
            Vector3 groundPos = GetWorldPosition(ray, 0.0f);
            player.target = groundPos;
            player.isMoving = true;
        }
        
        // Update camera
        UpdateGameCamera(&gameCamera, &player);
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            
            BeginMode3D(gameCamera.camera);
                // Draw ground grid
                DrawGrid(gridSize, 1.0f);
                
                // Draw player
                DrawCube(player.position, 1.0f, 2.0f, 1.0f, RED);
                DrawCubeWires(player.position, 1.0f, 2.0f, 1.0f, MAROON);
                
                // Draw target position indicator when moving
                if (player.isMoving) {
                    DrawSphere(player.target, 0.2f, GREEN);
                }
            EndMode3D();
            
            // Draw UI
            DrawText("Left click to move player", 10, 10, 20, DARKGRAY);
            DrawFPS(10, 40);
            
        EndDrawing();
    }

    CloseWindow();
    return 0;
}