// Address: 0x140063e10
// Ghidra name: FUN_140063e10
// ============ 0x140063e10 FUN_140063e10 (size=300) ============


void FUN_140063e10(longlong param_1)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  undefined4 local_res8;

  undefined4 local_resc;

  

  iVar3 = *(int *)(param_1 + 0x254);

  if ((iVar3 == 6) || (iVar3 == 7)) {

    lVar2 = *(longlong *)(param_1 + 0xb8);

    iVar3 = 0;

    if (*(longlong *)(param_1 + 0xc0) - lVar2 >> 3 != 0) {

      lVar4 = 0;

      do {

        lVar2 = *(longlong *)(lVar4 + lVar2);

        if (*(int *)(lVar2 + 0xc) == 8) {

          if (*(int *)(param_1 + 0x254) != 6) {

            local_resc = *(undefined4 *)(lVar2 + 0x2c);

            local_res8 = *(undefined4 *)(lVar2 + 0x28);

            cVar1 = FUN_1400c5740(&local_res8,*(longlong *)(param_1 + 0x78) + 0x40,0);

            if (cVar1 == '\0') goto LAB_140063ead;

          }

          *(undefined1 *)(*(longlong *)(lVar4 + *(longlong *)(param_1 + 0xb8)) + 0x11) = 1;

        }

LAB_140063ead:

        lVar2 = *(longlong *)(param_1 + 0xb8);

        iVar3 = iVar3 + 1;

        lVar4 = lVar4 + 8;

      } while ((ulonglong)(longlong)iVar3 < (ulonglong)(*(longlong *)(param_1 + 0xc0) - lVar2 >> 3))

      ;

    }

    FUN_1400cce00(param_1);

  }

  if ((*(char *)(DAT_1403f4e00 + 0x262) == '\0') && (*(int *)(DAT_1403fb0d8 + 0x324) == 0)) {

    *(undefined4 *)(DAT_1403fb0d8 + 0x440) = 0x14;

  }

  if (*(int *)(param_1 + 0x254) == 2) {

    *(undefined4 *)(DAT_1403fb0d8 + 0x308) = *(undefined4 *)(param_1 + 0x290);

  }

  *(int *)(param_1 + 0x254) = 0;

  return;

}




