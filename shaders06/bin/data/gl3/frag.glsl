#version 150

// this is how we receive the texture
uniform sampler2DRect tex0;
uniform sampler2DRect tex1;
uniform sampler2DRect imageMask;

in vec2 texCoordVarying;

out vec4 outputColor;

void main() {
    vec4 r = texture(tex0, texCoordVarying);
    vec4 g = texture(tex1, texCoordVarying);
    vec4 mask = texture(imageMask, texCoordVarying);

    vec4 color = vec4(0, 0, 0, 1.0);
    color = mix(color, r, mask.r);
    color = mix(color, g, mask.g);

    outputColor = color;
}
