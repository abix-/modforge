// Address: 0x1401ecb80
// Ghidra name: FUN_1401ecb80
// ============ 0x1401ecb80 FUN_1401ecb80 (size=241) ============


void FUN_1401ecb80(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,

                  undefined4 param_5,undefined8 param_6,longlong param_7)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  int iVar4;

  

  lVar1 = *(longlong *)(param_7 + 0x2e0);

  if (param_2 == 0x824c) {

    iVar4 = *(int *)(lVar1 + 0xc) + 1;

    lVar2 = FUN_140184230(*(undefined8 *)(lVar1 + 0x10),(longlong)iVar4 << 3);

    if (lVar2 != 0) {

      *(int *)(lVar1 + 0xc) = iVar4;

      *(longlong *)(lVar1 + 0x10) = lVar2;

      uVar3 = FUN_14012f0d0(param_6);

      *(undefined8 *)(*(longlong *)(lVar1 + 0x10) + -8 + (longlong)*(int *)(lVar1 + 0xc) * 8) =

           uVar3;

    }

  }

  if (*(code **)(lVar1 + 0x18) == (code *)0x0) {

    if (param_2 == 0x824c) {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0();

    }

    FUN_14012e080(6,&DAT_14039bf30,param_6);

  }

  else {

    (**(code **)(lVar1 + 0x18))

              (param_1,param_2,param_3,param_4,param_5,param_6,*(undefined8 *)(lVar1 + 0x20));

  }

  return;

}




