// Address: 0x140182620
// Ghidra name: FUN_140182620
// ============ 0x140182620 FUN_140182620 (size=373) ============


ulonglong FUN_140182620(byte *param_1)



{

  byte bVar1;

  int iVar2;

  undefined4 uVar3;

  size_t sVar4;

  undefined8 uVar5;

  ulonglong uVar6;

  uint uVar7;

  undefined **ppuVar8;

  ushort local_res8 [4];

  

  if (param_1 == (byte *)0x0) {

    return 0;

  }

  bVar1 = *param_1;

  uVar7 = (uint)bVar1;

  sVar4 = strlen((char *)param_1);

  if (bVar1 < 0xf0) {

    if (bVar1 < 0xe0) {

      if (uVar7 < 0xc0) {

        if (sVar4 != 1) goto LAB_140182724;

      }

      else {

        if (sVar4 != 2) goto LAB_140182724;

        uVar7 = (*param_1 & 0x1f) << 6 | param_1[1] & 0x3f;

      }

    }

    else {

      if (sVar4 != 3) goto LAB_140182724;

      uVar7 = ((*param_1 & 0xf) << 6 | param_1[1] & 0x3f) << 6 | param_1[2] & 0x3f;

    }

  }

  else {

    if (sVar4 != 4) goto LAB_140182724;

    uVar7 = (((*param_1 & 7) << 6 | param_1[1] & 0x3f) << 6 | param_1[2] & 0x3f) << 6 |

            param_1[3] & 0x3f;

  }

  if (uVar7 != 0) {

    uVar5 = FUN_1401831d0(0);

    iVar2 = FUN_140182b50(uVar5,uVar7,local_res8);

    if ((iVar2 != 0) && ((local_res8[0] & 0x2003) != 0)) {

      uVar7 = FUN_1401829a0(uVar5,iVar2,0);

    }

    return (ulonglong)uVar7;

  }

LAB_140182724:

  ppuVar8 = &PTR_s_LeftTab_1403e3940;

  uVar7 = 0;

  do {

    uVar7 = uVar7 + 1;

    iVar2 = FUN_14012ef60(param_1,*ppuVar8);

    if (iVar2 == 0) {

      return (ulonglong)(uVar7 | 0x20000000);

    }

    ppuVar8 = ppuVar8 + 1;

  } while (uVar7 < 7);

  uVar3 = FUN_140182bb0(param_1);

  uVar6 = FUN_140183200(uVar3,0,0);

  return uVar6;

}




