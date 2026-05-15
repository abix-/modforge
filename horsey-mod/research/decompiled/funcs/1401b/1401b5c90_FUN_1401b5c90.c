// Address: 0x1401b5c90
// Ghidra name: FUN_1401b5c90
// ============ 0x1401b5c90 FUN_1401b5c90 (size=192) ============


undefined8 *

FUN_1401b5c90(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

             undefined1 param_5,longlong param_6)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  undefined8 uVar3;

  undefined1 uVar4;

  longlong lVar5;

  

  uVar4 = param_5;

  lVar5 = param_6;

  puVar1 = (undefined8 *)FUN_1401b5a30();

  if (puVar1 == (undefined8 *)0x0) {

    return (undefined8 *)0x0;

  }

  puVar2 = (undefined8 *)FUN_1401841a0(1,0x28,param_3,param_4,uVar4,lVar5);

  *puVar2 = puVar1;

  *puVar1 = puVar2;

  *(undefined4 *)(puVar1 + 1) = 0;

  *(undefined4 *)(puVar2 + 2) = 1;

  *(undefined4 *)((longlong)puVar2 + 0x14) = 1;

  puVar1 = (undefined8 *)FUN_1401841a0(1,8);

  puVar2[1] = puVar1;

  *puVar1 = *puVar2;

  *(undefined1 *)(puVar2 + 3) = param_5;

  puVar2[4] = 0;

  if (param_6 != 0) {

    uVar3 = FUN_14012f0d0(param_6);

    puVar2[4] = uVar3;

  }

  return puVar2;

}




