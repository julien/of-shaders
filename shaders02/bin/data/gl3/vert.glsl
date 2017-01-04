#version 150

uniform mat4 modelViewProjectionMatrix;
in vec4 position;

uniform float time;

void main() {
    // the sine wave travels along the x-axis
    // so we use the x coordinate of each vertex for the
    // calculation but we displace all the vertex along the
    // y axis

    float displacementHeight = 100;
    float displacementY = sin(time + (position.x / 100.0)) * displacementHeight;

    vec4 modifiedPosition = modelViewProjectionMatrix * position;
    modifiedPosition.y += displacementY;

    gl_Position = modifiedPosition;
}
