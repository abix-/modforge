// Address: 0x140043600
// Ghidra name: FUN_140043600
// ============ 0x140043600 FUN_140043600 (size=185) ============


int FUN_140043600(longlong param_1,undefined4 param_2,undefined8 param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined1 local_28 [16];

  

  iVar3 = 0;

  if (param_4 < 1) {

    iVar3 = 0;

  }

  else {

    do {

      iVar2 = *(int *)(param_1 + 0x768) - *(int *)(param_1 + 0x764);

      iVar1 = param_4 - iVar3;

      if (iVar2 + iVar3 < param_4) {

        iVar1 = iVar2;

      }

      if (iVar1 != 0) {

        FUN_140049e00(param_2,param_3,iVar3,*(undefined4 *)(param_1 + 4),param_1 + 0x378,

                      *(int *)(param_1 + 0x764),iVar1);

      }

      *(int *)(param_1 + 0x764) = *(int *)(param_1 + 0x764) + iVar1;

      iVar3 = iVar3 + iVar1;

    } while (((iVar3 != param_4) && (iVar1 = FUN_140042b70(param_1,0,local_28), iVar1 != 0)) &&

            (iVar3 < param_4));

  }

  return iVar3;

}




