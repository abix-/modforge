// Address: 0x140043530
// Ghidra name: FUN_140043530
// ============ 0x140043530 FUN_140043530 (size=202) ============


int FUN_140043530(longlong param_1,int param_2,longlong param_3,int param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  undefined1 local_28 [16];

  

  iVar3 = 0;

  param_4 = param_4 / param_2;

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

        FUN_140049b70(param_2,param_3,*(undefined4 *)(param_1 + 4),param_1 + 0x378,

                      *(int *)(param_1 + 0x764),iVar1);

      }

      *(int *)(param_1 + 0x764) = *(int *)(param_1 + 0x764) + iVar1;

      iVar3 = iVar3 + iVar1;

      param_3 = param_3 + (longlong)(iVar1 * param_2) * 2;

    } while (((iVar3 != param_4) && (iVar1 = FUN_140042b70(param_1,0,local_28), iVar1 != 0)) &&

            (iVar3 < param_4));

  }

  return iVar3;

}




