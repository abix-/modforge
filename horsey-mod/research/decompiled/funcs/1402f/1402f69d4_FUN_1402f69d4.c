// Address: 0x1402f69d4
// Ghidra name: FUN_1402f69d4
// ============ 0x1402f69d4 FUN_1402f69d4 (size=167) ============


undefined4 FUN_1402f69d4(longlong param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  if (param_1 != 0) {

    iVar4 = 0;

    iVar5 = 0xe3;

    do {

      iVar2 = (iVar5 + iVar4) / 2;

      iVar3 = FUN_1402f5710(param_1,(&PTR_DAT_140397470)[(longlong)iVar2 * 2],0x55);

      if (iVar3 == 0) {

        iVar5 = *(int *)(&DAT_140397478 + (longlong)iVar2 * 0x10);

        if (iVar5 < 0) {

          return 0;

        }

        if (0xe3 < (ulonglong)(longlong)iVar5) {

          return 0;

        }

        return *(undefined4 *)(&DAT_140395a20 + (longlong)iVar5 * 0x10);

      }

      iVar1 = iVar2 + -1;

      if (-1 < iVar3) {

        iVar4 = iVar2 + 1;

        iVar1 = iVar5;

      }

      iVar5 = iVar1;

    } while (iVar4 <= iVar5);

  }

  return 0;

}




