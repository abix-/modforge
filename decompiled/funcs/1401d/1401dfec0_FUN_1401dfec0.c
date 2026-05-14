// Address: 0x1401dfec0
// Ghidra name: FUN_1401dfec0
// ============ 0x1401dfec0 FUN_1401dfec0 (size=348) ============


undefined1

FUN_1401dfec0(longlong param_1,longlong param_2,int *param_3,undefined8 param_4,undefined4 param_5,

             undefined8 param_6,undefined4 param_7,undefined8 param_8,undefined4 param_9)



{

  longlong lVar1;

  longlong lVar2;

  undefined1 uVar3;

  char cVar4;

  

  lVar1 = *(longlong *)(param_2 + 0x138);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar3 = FUN_14012e850("Texture is not currently available");

    return uVar3;

  }

  cVar4 = FUN_1401dfd20(*(undefined8 *)(lVar2 + 0x10),lVar1,*param_3,param_3[1],param_3[2],

                        param_3[3],param_4,param_5);

  if (cVar4 != '\0') {

    cVar4 = FUN_1401dfd20(*(undefined8 *)(lVar2 + 0x10),lVar1 + 0x50,*param_3 / 2,param_3[1] / 2,

                          (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_6,param_7);

    if (cVar4 != '\0') {

      cVar4 = FUN_1401dfd20(*(undefined8 *)(lVar2 + 0x10),lVar1 + 0x78,*param_3 / 2,param_3[1] / 2,

                            (param_3[2] + 1) / 2,(param_3[3] + 1) / 2,param_8,param_9);

      return cVar4 != '\0';

    }

  }

  return false;

}




