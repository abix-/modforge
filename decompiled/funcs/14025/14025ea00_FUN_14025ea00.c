// Address: 0x14025ea00
// Ghidra name: FUN_14025ea00
// ============ 0x14025ea00 FUN_14025ea00 (size=587) ============


ulonglong FUN_14025ea00(longlong param_1,longlong param_2,int param_3,int param_4,byte param_5,

                       byte param_6,byte param_7,byte param_8)



{

  byte bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  longlong lVar8;

  char cVar9;

  ulonglong uVar10;

  code *pcVar11;

  code *pcVar12;

  byte local_48;

  byte local_44;

  byte local_40;

  byte local_3c;

  

  local_48 = 1;

  cVar9 = FUN_1401489c0();

  if (cVar9 == '\0') {

    uVar10 = FUN_14012e850("Parameter \'%s\' is invalid","SDL_BlendPoints(): dst");

    return uVar10;

  }

  lVar8 = *(longlong *)(param_1 + 0x38);

  bVar1 = *(byte *)(lVar8 + 4);

  if (bVar1 < 8) {

    uVar10 = FUN_14012e850("SDL_BlendPoints(): Unsupported surface format");

    return uVar10;

  }

  if (param_4 - 1U < 2) {

    local_3c = (byte)(((uint)param_5 * (uint)param_8) / 0xff);

    local_40 = (byte)(((uint)param_6 * (uint)param_8) / 0xff);

    local_44 = (byte)(((uint)param_7 * (uint)param_8) / 0xff);

  }

  else {

    local_44 = param_7;

    local_40 = param_6;

    local_3c = param_5;

  }

  pcVar11 = (code *)0x0;

  if (bVar1 == 0xf) {

    if (*(int *)(lVar8 + 8) == 0x7c00) {

      pcVar12 = FUN_14025d330;

      goto LAB_14025eb75;

    }

  }

  else {

    if (bVar1 == 0x10) {

      pcVar12 = FUN_14025d820;

      if (*(int *)(lVar8 + 8) != 0xf800) {

        pcVar12 = pcVar11;

      }

    }

    else {

      if ((bVar1 != 0x20) || (*(int *)(lVar8 + 8) != 0xff0000)) goto LAB_14025eb5f;

      pcVar12 = FUN_14025e610;

      if (*(int *)(lVar8 + 0x14) != 0) {

        pcVar12 = FUN_14025c160;

      }

    }

    if (pcVar12 != (code *)0x0) goto LAB_14025eb75;

  }

LAB_14025eb5f:

  pcVar12 = FUN_14025dd40;

  if (*(int *)(lVar8 + 0x14) == 0) {

    pcVar12 = FUN_14025c580;

  }

LAB_14025eb75:

  iVar2 = *(int *)(param_1 + 100);

  iVar3 = *(int *)(param_1 + 0x68);

  iVar4 = *(int *)(param_1 + 0x6c);

  iVar5 = *(int *)(param_1 + 0x70);

  if (0 < (longlong)param_3) {

    do {

      iVar6 = *(int *)(param_2 + (longlong)pcVar11 * 8);

      if ((((iVar2 <= iVar6) && (iVar6 <= iVar2 + -1 + iVar4)) &&

          (iVar7 = *(int *)(param_2 + 4 + (longlong)pcVar11 * 8), iVar3 <= iVar7)) &&

         (iVar7 <= iVar3 + -1 + iVar5)) {

        local_48 = (*pcVar12)(param_1,iVar6,iVar7,param_4,local_3c,local_40,local_44,param_8);

      }

      pcVar11 = pcVar11 + 1;

    } while ((longlong)pcVar11 < (longlong)param_3);

  }

  return (ulonglong)local_48;

}




