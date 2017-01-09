#version 150

// this is how we receive the texture
uniform sampler2DRect tex0;
uniform sampler2DRect maskTex;

in vec2 texCoordVarying;

out vec4 outputColor;

void main() {
    // get rgb fom tex0
    vec3 src = texture(tex0, texCoordVarying).rgb;

    // get alpha from mask
    float mask = texture(maskTex, texCoordVarying).r;

    outputColor = vec4(src, mask);
}
