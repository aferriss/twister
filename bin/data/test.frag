//setup for 2 texture
varying vec2 texcoord0;
varying vec2 texcoord1;

uniform sampler2D tex0;
uniform vec2 res;

void main(){
    vec4 color = texture2D(tex0, texcoord0);
    
//    float stripeCount = 8.0 + 0.8*res.y;//*sin(0.1*iGlobalTime);
//    float stripeWidth = res.y / (2.0*stripeCount);
//    vec4 stripes;
//    if(mod(gl_FragCoord.y, 2.0*stripeWidth) > stripeWidth)
//    {
//        //stripes = vec4(1.0, 1.0, 1.0,1.0);
////        discard;
//    }
//    else
//    {
//        
//        //stripes = vec4(0.0, 0.0, 0.0,1.0);
//    }
//    if(color.r > 240.0/255.0 && color.g > 230.0/255.0 && color.b > 220.0/255.0 && color.r < 250.0/255.0
//       && color.g < 250.0/255.0
//       && color.b < 250.0/255.0){
//        discard;
//    }
    
    
    gl_FragColor = color;//vec4(1.0,0.0,0.0,1.0);//vec4(texcoord0.xy, 1.0,1.0);//vec4(gray, gray, gray, 1.0);
}
