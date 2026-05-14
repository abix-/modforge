// Address: 0x14013d4e0
// Ghidra name: FUN_14013d4e0
// ============ 0x14013d4e0 FUN_14013d4e0 (size=118) ============


undefined8 FUN_14013d4e0(undefined4 *param_1)



{

  undefined8 uVar1;

  undefined1 local_res8 [32];

  undefined4 local_418;

  undefined4 uStack_414;

  undefined4 uStack_410;

  undefined4 uStack_40c;

  undefined1 local_408 [1024];

  

  if (*(char *)((longlong)param_1 + 0xf) != '\x01') {

    return 0;

  }

  FUN_14012f1a0(local_408,"none,*,",0x400);

  FUN_14012f120(local_408,

                "a:b0,b:b1,x:b2,y:b3,back:b6,start:b7,leftstick:b8,rightstick:b9,leftshoulder:b4,rightshoulder:b5,dpup:b10,dpdown:b12,dpleft:b13,dpright:b11,leftx:a1,lefty:a0~,rightx:a3,righty:a2~,lefttrigger:a4,righttrigger:a5,"

                ,0x400);

  local_418 = *param_1;

  uStack_414 = param_1[1];

  uStack_410 = param_1[2];

  uStack_40c = param_1[3];

  uVar1 = FUN_14013fc10(&local_418,local_408,local_res8,0);

  return uVar1;

}




