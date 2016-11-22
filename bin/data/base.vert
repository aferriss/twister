varying vec2 texcoord0;
varying vec2 texcoord1;
uniform float time;
uniform vec2 res;
uniform sampler2D tex0;
vec4 DoTwist( vec4 pos, float t )
{
    float st = sin(t);
    float ct = cos(t);
    vec4 new_pos;
    
    new_pos.x = pos.x*ct - pos.z*st;
    new_pos.z = pos.x*st + pos.z*ct;
    
    new_pos.y = pos.y;
    new_pos.w = pos.w;
    
    return( new_pos );
}

void main()
{
    // transform texcoords
    texcoord0 = vec2(gl_TextureMatrix[0] * gl_MultiTexCoord0);
    texcoord1 = vec2(gl_TextureMatrix[1] * gl_MultiTexCoord0);
    
    float angle_deg_max = 3600.0;
    // perform standard transform on vertex
    float angle_deg = 1000.0;//sin(time)*100.0;//angle_deg_max*sin(time);
    float angle_rad = angle_deg * 3.14159 / 180.0;
    float vY = gl_Vertex.y;
    float ang = (res.y*0.5 + vY)/res.y * (angle_rad + time);
    vec4 twistedPosition = DoTwist(gl_Vertex, ang);
    vec4 twistedNormal = DoTwist(vec4(gl_Normal, ang), ang);
    
    vec4 img = texture2D(tex0, texcoord0);
    float avg = dot(img.rgb, vec3(1.0))*0.333333;
    avg = -1.0 + 2.0 * avg;
    vec3 disp = avg * normalize(twistedNormal.xyz);
    
    //twistedPosition.xyz += disp*10.0;
    gl_Position = gl_ModelViewProjectionMatrix * twistedPosition;// ftransform();


}
