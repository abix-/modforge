// Address: 0x1401a18d0
// Ghidra name: FUN_1401a18d0
// ============ 0x1401a18d0 FUN_1401a18d0 (size=213) ============


undefined8

FUN_1401a18d0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,

             undefined4 param_5,undefined8 *param_6,undefined8 param_7,undefined8 param_8,

             undefined4 param_9)



{

  int iVar1;

  undefined8 uVar2;

  undefined8 in_stack_ffffffffffffffe8;

  undefined4 uVar3;

  

  uVar3 = (undefined4)((ulonglong)in_stack_ffffffffffffffe8 >> 0x20);

  *param_6 = 8;

  *(undefined4 *)(param_6 + 1) = 0;

  iVar1 = FUN_1401a32b0();

  if (iVar1 == 0) {

    iVar1 = FUN_1401a16c0(param_1);

    if (iVar1 == 0) {

      FUN_14019f050("Image not of any known type, or corrupt");

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_1401a15b0(param_1,param_2,param_3,param_4,param_5,0,param_6);

    }

  }

  else {

    uVar2 = FUN_1401a3260(param_1,param_2,param_3,param_4,param_5,param_8,CONCAT44(uVar3,param_9),

                          param_6);

  }

  return uVar2;

}




