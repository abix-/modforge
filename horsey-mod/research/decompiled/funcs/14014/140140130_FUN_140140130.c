// Address: 0x140140130
// Ghidra name: FUN_140140130
// ============ 0x140140130 FUN_140140130 (size=1081) ============


void FUN_140140130(undefined8 param_1,undefined4 *param_2,longlong param_3)



{

  char *pcVar1;

  char *pcVar2;

  undefined1 local_res10 [8];

  undefined4 local_498;

  undefined4 uStack_494;

  undefined4 uStack_490;

  undefined4 uStack_48c;

  undefined1 local_488 [1024];

  char local_88 [128];

  

  FUN_14015b420(param_2,0);

  FUN_14012f1a0(local_88,param_1,0x80);

  pcVar2 = local_88;

  while (local_88[0] != '\0') {

    if (local_88[0] == ',') {

      *pcVar2 = ' ';

    }

    pcVar1 = pcVar2 + 1;

    pcVar2 = pcVar2 + 1;

    local_88[0] = *pcVar1;

  }

  FUN_14012ef10(local_488,0x400,"none,%s,",local_88);

  FUN_14013fef0(local_488,0x400,&DAT_1403301c0,param_3);

  FUN_14013fef0(local_488,0x400,&DAT_1403301c4,param_3 + 8);

  FUN_14013fef0(local_488,0x400,&DAT_14030a29c,param_3 + 0x10);

  FUN_14013fef0(local_488,0x400,&DAT_14030a2a0,param_3 + 0x18);

  FUN_14013fef0(local_488,0x400,&DAT_14030dbb8,param_3 + 0x20);

  FUN_14013fef0(local_488,0x400,"guide",param_3 + 0x28);

  FUN_14013fef0(local_488,0x400,"start",param_3 + 0x30);

  FUN_14013fef0(local_488,0x400,"leftstick",param_3 + 0x38);

  FUN_14013fef0(local_488,0x400,"rightstick",param_3 + 0x40);

  FUN_14013fef0(local_488,0x400,"leftshoulder",param_3 + 0x48);

  FUN_14013fef0(local_488,0x400,"rightshoulder",param_3 + 0x50);

  FUN_14013fef0(local_488,0x400,&DAT_1403302cc,param_3 + 0x58);

  FUN_14013fef0(local_488,0x400,"dpdown",param_3 + 0x60);

  FUN_14013fef0(local_488,0x400,"dpleft",param_3 + 0x68);

  FUN_14013fef0(local_488,0x400,"dpright",param_3 + 0x70);

  FUN_14013fef0(local_488,0x400,"misc1",param_3 + 0x78);

  FUN_14013fef0(local_488,0x400,"misc2",param_3 + 0x80);

  FUN_14013fef0(local_488,0x400,"misc3",param_3 + 0x88);

  FUN_14013fef0(local_488,0x400,"misc4",param_3 + 0x90);

  FUN_14013fef0(local_488,0x400,"misc5",param_3 + 0x98);

  FUN_14013fef0(local_488,0x400,"misc6",param_3 + 0xa0);

  FUN_14013fef0(local_488,0x400,"paddle1",param_3 + 0xa8);

  FUN_14013fef0(local_488,0x400,"paddle2",param_3 + 0xb0);

  FUN_14013fef0(local_488,0x400,"paddle3",param_3 + 0xb8);

  FUN_14013fef0(local_488,0x400,"paddle4",param_3 + 0xc0);

  FUN_14013fef0(local_488,0x400,"leftx",param_3 + 200);

  FUN_14013fef0(local_488,0x400,"lefty",param_3 + 0xd0);

  FUN_14013fef0(local_488,0x400,"rightx",param_3 + 0xd8);

  FUN_14013fef0(local_488,0x400,"righty",param_3 + 0xe0);

  FUN_14013fef0(local_488,0x400,"lefttrigger",param_3 + 0xe8);

  FUN_14013fef0(local_488,0x400,"righttrigger",param_3 + 0xf0);

  FUN_14013fef0(local_488,0x400,"touchpad",param_3 + 0xf8);

  local_498 = *param_2;

  uStack_494 = param_2[1];

  uStack_490 = param_2[2];

  uStack_48c = param_2[3];

  FUN_14013fc10(&local_498,local_488,local_res10,0);

  return;

}




