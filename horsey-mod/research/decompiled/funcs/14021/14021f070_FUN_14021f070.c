// Address: 0x14021f070
// Ghidra name: FUN_14021f070
// ============ 0x14021f070 FUN_14021f070 (size=121) ============


void FUN_14021f070(longlong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined8 param_6,undefined4 param_7,char param_8)



{

  uint uVar1;

  uint uVar2;

  

  uVar2 = (param_8 != '\0') + 0x50010000;

  uVar1 = uVar2 | 0x20000;

  if (*(short *)(param_1 + 0x20) != 0) {

    uVar1 = uVar2;

  }

  FUN_14021f0f0(param_1,0x80,uVar1,0,param_2,param_3,param_4,param_5,param_7,param_6,0);

  return;

}




