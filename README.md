# IGE
## Prerequisites:
1. Visual Studio 2022 - build tools. It is required for compiling custom behaviour scripts. Path to MSVC compiler is hardcoded in Engine/src/Utils/ScriptAPI.h.

## Design:
There are two projects in the solution.
The Core project builds to a dll which contains some base classes which is imported by Engine project and Custom Scripts. The Core.dll was created to restrict the visiblity of internal funtions of game engine while working as a bridge between custom user script and engine.

The Engine projects builds to an .exe file which is the main entry point of the engine. It runs the main loop and performs all internal communications.

## Guide:

### 1. Creating GameObject
On the menu bar of "Heirarchy" Panel which is on the left most side click on "Create" button then "GameObject" button to create a gameobject.

### 2. Adding Components to GameObject
Select the gameobject on which you want to add components then on the right "Inspector" panel click on the "Add Component" button to add a component.

#### Components Guide:
##### 1. Transform
It holds position, scale and rotation of gameobject.

##### 2. Mesh
It holds the vertices, indices of mesh which you want to draw. As there is no mesh generator you can use the square.mesh from src/Assets/Meshes

##### 3. Rigidbody
It holds the velocity, acceleration and other rigidbody properties.

##### 4. BoxCollider2D
It is a simple collider for 2D boxes.

##### 5. Script
It is user defined custom behaviour script for gameobject. **Note**- MSVS 2022 build tools required to build the scripts on runtime.

### 3. Saving the Scene
Click on the Save button on menu of left panel. Choose a location and the scene will be saved with .cn extension.

### 4. Loading the Scene
Similiar to above.
