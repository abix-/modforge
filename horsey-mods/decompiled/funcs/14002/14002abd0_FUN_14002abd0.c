// Address: 0x14002abd0
// Ghidra name: FUN_14002abd0
// ============ 0x14002abd0 FUN_14002abd0 (size=487) ============


char * FUN_14002abd0(longlong *param_1,undefined8 param_2,longlong *param_3,undefined4 param_4)



{

  char cVar1;

  ulonglong uVar2;

  undefined *puVar3;

  longlong lVar4;

  char *pcVar5;

  longlong *plVar6;

  char *pcVar7;

  longlong lVar8;

  

  for (plVar6 = param_1; plVar6 != (longlong *)0x0; plVar6 = (longlong *)plVar6[3]) {

    lVar4 = (**(code **)(*plVar6 + 0x20))(plVar6);

    if (lVar4 != 0) {

      lVar4 = (**(code **)(*plVar6 + 0x20))(plVar6);

      goto LAB_14002ac1d;

    }

  }

  lVar4 = 0;

LAB_14002ac1d:

  pcVar5 = (char *)FUN_140028820(param_2,param_4);

  if (param_3 != (longlong *)0x0) {

    FUN_140028650(param_3,pcVar5,param_4);

    param_1[1] = *param_3;

  }

  puVar3 = PTR_s_Error_parsing_Unknown__14039a3f8;

  if (((pcVar5 == (char *)0x0) || (*pcVar5 == '\0')) || (*pcVar5 != '<')) {

    if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

      lVar8 = -1;

      *(undefined1 *)(lVar4 + 0x68) = 1;

      *(undefined4 *)(lVar4 + 0x6c) = 9;

      do {

        lVar8 = lVar8 + 1;

      } while (puVar3[lVar8] != '\0');

      FUN_140027f50(lVar4 + 0x70);

      *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

      if ((pcVar5 != (char *)0x0) && (param_3 != (longlong *)0x0)) {

        FUN_140028650(param_3,pcVar5,param_4);

        *(longlong *)(lVar4 + 0x94) = *param_3;

      }

    }

    pcVar7 = (char *)0x0;

  }

  else {

    FUN_140027f50(param_1 + 7,&DAT_14039bcb9,0);

    puVar3 = PTR_s_Error_parsing_Unknown__14039a3f8;

    while (pcVar7 = pcVar5 + 1, PTR_s_Error_parsing_Unknown__14039a3f8 = puVar3,

          pcVar7 != (char *)0x0) {

      cVar1 = *pcVar7;

      if ((cVar1 == '\0') || (cVar1 == '>')) goto LAB_14002ad2e;

      uVar2 = param_1[9];

      pcVar5 = pcVar7;

      if (uVar2 < (ulonglong)param_1[10]) {

        param_1[9] = uVar2 + 1;

        plVar6 = param_1 + 7;

        if (0xf < (ulonglong)param_1[10]) {

          plVar6 = (longlong *)param_1[7];

        }

        *(char *)((longlong)plVar6 + uVar2) = cVar1;

        *(undefined1 *)((longlong)plVar6 + uVar2 + 1) = 0;

        puVar3 = PTR_s_Error_parsing_Unknown__14039a3f8;

      }

      else {

        FUN_1400280d0(param_1 + 7);

        puVar3 = PTR_s_Error_parsing_Unknown__14039a3f8;

      }

    }

    if ((lVar4 != 0) && (*(char *)(lVar4 + 0x68) == '\0')) {

      lVar8 = -1;

      *(undefined1 *)(lVar4 + 0x68) = 1;

      *(undefined4 *)(lVar4 + 0x6c) = 9;

      do {

        lVar8 = lVar8 + 1;

      } while (puVar3[lVar8] != '\0');

      FUN_140027f50(lVar4 + 0x70);

      *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

    }

LAB_14002ad2e:

    if (*pcVar7 == '>') {

      pcVar7 = pcVar5 + 2;

    }

  }

  return pcVar7;

}




