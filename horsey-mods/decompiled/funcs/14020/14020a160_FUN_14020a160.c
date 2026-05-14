// Address: 0x14020a160
// Ghidra name: FUN_14020a160
// ============ 0x14020a160 FUN_14020a160 (size=289) ============


ulonglong FUN_14020a160(longlong param_1,undefined1 *param_2,longlong *param_3,undefined1 param_4)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  int iVar5;

  ulonglong uVar6;

  uint uVar7;

  ulonglong uVar8;

  

  uVar4 = 0;

  uVar3 = uVar4;

  uVar6 = uVar4;

  uVar8 = uVar4;

  iVar5 = DAT_1403fd238;

  if (0 < DAT_1403fd238) {

    do {

      lVar1 = *(longlong *)(uVar6 + DAT_1403fd230);

      if ((*(char *)(lVar1 + 0x51) != '\0') && (*(char *)(lVar1 + 0x50) == '\0')) {

        *param_3 = lVar1;

        uVar3 = (ulonglong)((int)uVar3 + 1);

        iVar5 = DAT_1403fd238;

      }

      uVar7 = (int)uVar8 + 1;

      uVar6 = uVar6 + 8;

      uVar8 = (ulonglong)uVar7;

    } while ((int)uVar7 < iVar5);

    if ((int)uVar3 == 1) {

      *(char *)(lVar1 + 0x52) = *(char *)(lVar1 + 0x52) + '\x01';

      *param_2 = *(undefined1 *)(lVar1 + 0x52);

      return uVar3 & 0xff;

    }

  }

  uVar3 = uVar4;

  uVar6 = uVar4;

  if (0 < iVar5) {

    do {

      lVar1 = *(longlong *)(uVar6 + DAT_1403fd230);

      cVar2 = FUN_14020b8a0(param_1,lVar1,param_4);

      if (cVar2 != '\0') {

        *param_3 = lVar1;

        uVar4 = (ulonglong)((int)uVar4 + 1);

        *(char *)(lVar1 + 0x52) = *(char *)(lVar1 + 0x52) + '\x01';

        *param_2 = *(undefined1 *)(lVar1 + 0x52);

        iVar5 = DAT_1403fd238;

      }

      uVar7 = (int)uVar3 + 1;

      uVar3 = (ulonglong)uVar7;

      uVar6 = uVar6 + 8;

    } while ((int)uVar7 < iVar5);

    if ((int)uVar4 == 1) {

      return (ulonglong)(*(char *)(param_1 + 0x14) != '\0');

    }

  }

  return 0;

}




