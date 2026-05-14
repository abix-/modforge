// Address: 0x1401aa480
// Ghidra name: FUN_1401aa480
// ============ 0x1401aa480 FUN_1401aa480 (size=764) ============


char * FUN_1401aa480(short param_1,ushort param_2,char *param_3,char *param_4,char *param_5)



{

  char cVar1;

  undefined4 uVar2;

  int iVar3;

  uint uVar4;

  size_t sVar5;

  size_t sVar6;

  char *pcVar7;

  size_t sVar8;

  ulonglong uVar9;

  ulonglong uVar10;

  ulonglong uVar11;

  char *_Str;

  char *pcVar12;

  undefined **ppuVar13;

  undefined8 in_stack_ffffffffffffffc8;

  undefined4 uVar14;

  

  uVar14 = (undefined4)((ulonglong)in_stack_ffffffffffffffc8 >> 0x20);

  pcVar12 = "";

  if (param_3 != (char *)0x0) {

    pcVar12 = param_3;

  }

  _Str = "";

  if (param_4 != (char *)0x0) {

    _Str = param_4;

  }

  cVar1 = *pcVar12;

  while (cVar1 == ' ') {

    pcVar12 = pcVar12 + 1;

    cVar1 = *pcVar12;

  }

  cVar1 = *_Str;

  while (cVar1 == ' ') {

    pcVar7 = _Str + 1;

    _Str = _Str + 1;

    cVar1 = *pcVar7;

  }

  if (cVar1 == '\0') {

    if ((param_1 == 0) && (param_2 == 0)) {

      if (param_5 == (char *)0x0) {

        return (char *)0x0;

      }

    }

    else {

      uVar2 = FUN_140157b80(param_1,param_2,0,1);

      switch(uVar2) {

      case 2:

        param_5 = "Xbox 360 Controller";

        break;

      case 3:

        param_5 = "Xbox One Controller";

        break;

      case 4:

        param_5 = "PS3 Controller";

        break;

      case 5:

        param_5 = "PS4 Controller";

        break;

      case 6:

        param_5 = "DualSense Wireless Controller";

        break;

      case 7:

        param_5 = "Nintendo Switch Pro Controller";

        break;

      default:

        pcVar7 = (char *)FUN_1401841f0(0xe);

        if (pcVar7 == (char *)0x0) {

          return (char *)0x0;

        }

        FUN_14012ef10(pcVar7,0xe,"0x%.4x/0x%.4x",param_1,CONCAT44(uVar14,(uint)param_2));

        goto LAB_1401aa606;

      }

    }

  }

  else {

    param_5 = _Str;

    if (*pcVar12 != '\0') {

      sVar5 = strlen(pcVar12);

      sVar6 = strlen(_Str);

      pcVar7 = (char *)FUN_1401841f0(sVar5 + sVar6 + 2);

      if (pcVar7 == (char *)0x0) {

        return (char *)0x0;

      }

      FUN_14012ef10(pcVar7,sVar5 + sVar6 + 2,"%s %s",pcVar12,_Str);

      goto LAB_1401aa606;

    }

  }

  pcVar7 = (char *)FUN_14012f0d0(param_5);

  if (pcVar7 == (char *)0x0) {

    return (char *)0x0;

  }

LAB_1401aa606:

  for (sVar5 = strlen(pcVar7); (sVar5 != 0 && (pcVar7[sVar5 - 1] == ' ')); sVar5 = sVar5 - 1) {

  }

  pcVar7[sVar5] = '\0';

  if (sVar5 != 1) {

    pcVar12 = pcVar7;

    do {

      if ((*pcVar12 == ' ') && (pcVar12[1] == ' ')) {

        FUN_1402f8e20(pcVar12,pcVar12 + 1,pcVar7 + (sVar5 - (longlong)pcVar12));

        sVar5 = sVar5 - 1;

      }

      else {

        pcVar12 = pcVar12 + 1;

      }

    } while ((ulonglong)((longlong)pcVar12 - (longlong)pcVar7) < sVar5 - 1);

  }

  uVar9 = 0;

  ppuVar13 = &PTR_s__Standard_system_devices__1403e3d70;

  do {

    sVar6 = strlen(*ppuVar13);

    iVar3 = FUN_14012f260(pcVar7,*ppuVar13,sVar6);

    if (iVar3 == 0) {

      sVar8 = strlen((&PTR_DAT_1403e3d78)[uVar9 * 2]);

      if (sVar8 <= sVar6) {

        FUN_1402f8e20(pcVar7,(&PTR_DAT_1403e3d78)[uVar9 * 2],sVar8);

        FUN_1402f8e20(pcVar7 + sVar8,pcVar7 + sVar6,(sVar5 - sVar6) + 1);

        sVar5 = sVar5 + (sVar8 - sVar6);

      }

      break;

    }

    uVar9 = uVar9 + 1;

    ppuVar13 = ppuVar13 + 2;

  } while (uVar9 < 0xe);

  uVar9 = 1;

  if (1 < sVar5 - 1) {

    do {

      uVar4 = FUN_1401aa2e0(pcVar7,pcVar7 + uVar9);

      uVar10 = (ulonglong)(int)uVar4;

      uVar11 = uVar10;

      if (0 < (int)uVar4) {

        do {

          uVar4 = (uint)uVar11;

          if ((pcVar7[uVar10] == ' ') || (pcVar7[uVar10] == '-')) {

            FUN_1402f8e20(pcVar7,pcVar7 + (longlong)(int)uVar4 + 1,sVar5 - (longlong)(int)uVar4);

            break;

          }

          uVar4 = uVar4 - 1;

          uVar11 = (ulonglong)uVar4;

          uVar10 = uVar10 - 1;

        } while (0 < (longlong)uVar10);

      }

    } while (((int)uVar4 < 1) && (uVar9 = uVar9 + 1, uVar9 < sVar5 - 1));

  }

  return pcVar7;

}




