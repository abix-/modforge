// Address: 0x1401ff7b0
// Ghidra name: FUN_1401ff7b0
// ============ 0x1401ff7b0 FUN_1401ff7b0 (size=298) ============


undefined1

FUN_1401ff7b0(longlong param_1,longlong param_2,int *param_3,undefined8 param_4,undefined4 param_5,

             undefined8 param_6,undefined4 param_7)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined1 uVar3;

  char cVar4;

  bool bVar5;

  

  lVar1 = *(longlong *)(param_2 + 0x138);

  uVar2 = *(undefined8 *)(param_1 + 0x2e0);

  if (lVar1 == 0) {

    uVar3 = FUN_14012e850("Texture is not currently available");

    return uVar3;

  }

  cVar4 = FUN_1401ff520(uVar2,*(undefined8 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x24),0,*param_3,

                        param_3[1],param_3[2],param_3[3],param_4,param_5,lVar1 + 0x20);

  if (cVar4 == '\0') {

    bVar5 = false;

  }

  else {

    cVar4 = FUN_1401ff520(uVar2,*(undefined8 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x24),1,

                          *param_3 / 2,param_3[1] / 2,(param_3[2] + 1) / 2,(param_3[3] + 1) / 2,

                          param_6,param_7,lVar1 + 0x20);

    bVar5 = cVar4 != '\0';

  }

  return bVar5;

}




