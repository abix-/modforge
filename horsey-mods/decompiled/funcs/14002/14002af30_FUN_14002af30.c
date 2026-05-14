// Address: 0x14002af30
// Ghidra name: FUN_14002af30
// ============ 0x14002af30 FUN_14002af30 (size=589) ============


char * FUN_14002af30(longlong *param_1,undefined8 param_2,longlong *param_3,undefined4 param_4)



{

  ulonglong uVar1;

  ulonglong uVar2;

  undefined *puVar3;

  longlong lVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  longlong *plVar8;

  longlong lVar9;

  

  for (plVar8 = param_1; plVar8 != (longlong *)0x0; plVar8 = (longlong *)plVar8[3]) {

    lVar4 = (**(code **)(*plVar8 + 0x20))(plVar8);

    if (lVar4 != 0) {

      lVar4 = (**(code **)(*plVar8 + 0x20))(plVar8);

      goto LAB_14002af7f;

    }

  }

  lVar4 = 0;

LAB_14002af7f:

  FUN_140027f50(param_1 + 7,&DAT_14039bcb9,0);

  pcVar5 = (char *)FUN_140028820(param_2,param_4);

  if (param_3 != (longlong *)0x0) {

    FUN_140028650(param_3,pcVar5,param_4);

    param_1[1] = *param_3;

  }

  pcVar7 = "<!--";

  if (pcVar5 == (char *)0x0) {

    FID_conflict__assert(L"p",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21b);

  }

  else {

    pcVar6 = pcVar5;

    if (*pcVar5 != '\0') {

      do {

        if ((*pcVar7 == '\0') || (*pcVar6 != *pcVar7)) break;

        pcVar6 = pcVar6 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar6 != '\0');

      if (*pcVar7 == '\0') {

        FUN_140027f50(param_1 + 7,&DAT_14039bcb9,0);

        pcVar5 = pcVar5 + 4;

        do {

          if (pcVar5 == (char *)0x0) {

            return (char *)0x0;

          }

          if (*pcVar5 == '\0') {

            return pcVar5;

          }

          pcVar6 = "-->";

          pcVar7 = pcVar5;

          do {

            if ((*pcVar6 == '\0') || (*pcVar7 != *pcVar6)) break;

            pcVar7 = pcVar7 + 1;

            pcVar6 = pcVar6 + 1;

          } while (*pcVar7 != '\0');

          if (*pcVar6 == '\0') {

            return pcVar5 + 3;

          }

          uVar1 = param_1[10];

          uVar2 = param_1[9];

          if (uVar1 == uVar2) {

            FUN_140027c80(param_1 + 7,1,uVar1,pcVar5,1);

          }

          else {

            param_1[9] = uVar2 + 1;

            plVar8 = param_1 + 7;

            if (0xf < uVar1) {

              plVar8 = (longlong *)param_1[7];

            }

            *(char *)((longlong)plVar8 + uVar2) = *pcVar5;

            *(undefined1 *)((longlong)plVar8 + uVar2 + 1) = 0;

          }

          pcVar5 = pcVar5 + 1;

        } while( true );

      }

      goto LAB_14002b001;

    }

  }

  FID_conflict__assert(L"0",L"C:\\dev\\tinyxml\\tinyxmlparser.cpp",0x21f);

LAB_14002b001:

  puVar3 = PTR_s_Error_parsing_Comment__14039a400;

  if (*(char *)(lVar4 + 0x68) == '\0') {

    lVar9 = -1;

    *(undefined1 *)(lVar4 + 0x68) = 1;

    *(undefined4 *)(lVar4 + 0x6c) = 10;

    do {

      lVar9 = lVar9 + 1;

    } while (puVar3[lVar9] != '\0');

    FUN_140027f50(lVar4 + 0x70);

    *(undefined8 *)(lVar4 + 0x94) = 0xffffffffffffffff;

    if ((pcVar5 != (char *)0x0) && (param_3 != (longlong *)0x0)) {

      FUN_140028650(param_3,pcVar5,param_4);

      *(longlong *)(lVar4 + 0x94) = *param_3;

    }

  }

  return (char *)0x0;

}




