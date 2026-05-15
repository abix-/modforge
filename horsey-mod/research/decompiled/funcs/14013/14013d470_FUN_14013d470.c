// Address: 0x14013d470
// Ghidra name: FUN_14013d470
// ============ 0x14013d470 FUN_14013d470 (size=101) ============


void FUN_14013d470(undefined4 *param_1)



{

  undefined1 local_res8 [32];

  undefined4 local_418;

  undefined4 uStack_414;

  undefined4 uStack_410;

  undefined4 uStack_40c;

  undefined1 local_408 [1024];

  

  FUN_14012f1a0(local_408,"none,*,",0x400);

  FUN_14012f120(local_408,

                "a:b0,b:b1,x:b2,y:b3,back:b6,guide:b10,start:b7,leftstick:b8,rightstick:b9,leftshoulder:b4,rightshoulder:b5,dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,leftx:a0,lefty:a1,rightx:a2,righty:a3,lefttrigger:a4,righttrigger:a5,"

                ,0x400);

  local_418 = *param_1;

  uStack_414 = param_1[1];

  uStack_410 = param_1[2];

  uStack_40c = param_1[3];

  FUN_14013fc10(&local_418,local_408,local_res8,0);

  return;

}




