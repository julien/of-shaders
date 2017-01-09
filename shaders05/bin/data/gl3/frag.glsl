#version 150

// this is how we receive the texture
uniform sampler2DRect tex0;
uniform sampler2DRect imageMask;

in vec2 texCoordVarying;

uniform float time;

out vec4 outputColor;

void main() {
    vec4 texel0 = texture(tex0, texCoordVarying);
    vec4 texel1 = texture(imageMask, texCoordVarying);


    outputColor = vec4(texel0.rgb, texel0.a * texel1.a);
}
