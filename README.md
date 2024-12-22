# Templated Building System

## Overview

This repository contains a set of templates designed to help you quickly set up projects for prototyping. Whether you're developing a dynamic library, a static library, or an OpenGL project, these templates provide a solid foundation to get started efficiently.

## Credits

[Dr. Jonas Birch](https://www.youtube.com/watch?v=mRHy0e58S0s)

## Instructions

* Create a folder in a global location
* Copy templates folder in global location for example **/var/prjbld** 
* Copy prjbld.sh in a global location **/usr/bin/prjbld**  or **/usr/loca/bin/prjbld** 
* Set script running permission **chmod 755 prjbld** 

## Template

* default.c: an empty project (just main)
* dynamic.c: a dynamic library project
* static.c : a static library project
* opengl.c : a basic OpenGL project
* raylib.c : a raylib based project. The project contains raylib rev5