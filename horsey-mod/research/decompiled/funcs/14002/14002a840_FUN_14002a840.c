// Address: 0x14002a840
// Ghidra name: FUN_14002a840
// ============ 0x14002a840 FUN_14002a840 (size=616) ============


char * FUN_14002a840(longlong *param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)



{

  byte bVar1;

  int iVar2;

  longlong lVar3;

  char *pcVar4;

  longlong *plVar5;

  undefined8 uVar6;

  longlong lVar7;

  char *pcVar8;

  longlong *plVar9;

  ulonglong uVar10;

  

  lVar7 = 0;

  plVar9 = param_1;

  do {

    if (plVar9 == (longlong *)0x0) {

LAB_14002a88e:

      pcVar4 = (char *)FUN_140028820(param_2,param_4);

      do {

        if (pcVar4 == (char *)0x0) {

          if ((lVar7 != 0) && (*(char *)(lVar7 + 0x68) == '\0')) {

            *(undefined1 *)(lVar7 + 0x68) = 1;

            *(undefined4 *)(lVar7 + 0x6c) = 5;

            lVar3 = -1;

            do {

              lVar3 = lVar3 + 1;

            } while (PTR_s_Error_reading_Element_value__14039a3d8[lVar3] != '\0');

            FUN_140027f50(lVar7 + 0x70);

            *(undefined8 *)(lVar7 + 0x94) = 0xffffffffffffffff;

          }

          return (char *)0x0;

        }

        if (*pcVar4 == '\0') {

          return pcVar4;

        }

        if (*pcVar4 == '<') {

          pcVar8 = "</";

          do {

            if (*pcVar8 == '\0') {

              return pcVar4;

            }

          } while (((pcVar4 + -0x14039c084)[(longlong)pcVar8] == *pcVar8) &&

                  (pcVar8 = pcVar8 + 1, (pcVar4 + -0x14039c084)[(longlong)pcVar8] != '\0'));

          if (*pcVar8 == '\0') {

            return pcVar4;

          }

          plVar9 = (longlong *)FUN_1400297b0(param_1,pcVar4,param_4);

          if (plVar9 == (longlong *)0x0) {

            return (char *)0x0;

          }

          uVar6 = (**(code **)(*plVar9 + 0x10))(plVar9,pcVar4,param_3,param_4);

          FUN_140025120(param_1,plVar9);

        }

        else {

          plVar5 = (longlong *)FUN_1402c704c(0x70);

          plVar5[1] = -1;

          plVar5[2] = 0;

          plVar5[7] = 0;

          plVar5[8] = 0;

          plVar5[9] = 0;

          plVar5[10] = 0xf;

          *(undefined1 *)(plVar5 + 7) = 0;

          plVar5[3] = 0;

          *(undefined4 *)(plVar5 + 4) = 4;

          plVar5[5] = 0;

          plVar5[6] = 0;

          plVar5[0xb] = 0;

          plVar5[0xc] = 0;

          *plVar5 = (longlong)TiXmlText::vftable;

          plVar9 = plVar5 + 7;

          if (0xf < (ulonglong)plVar5[10]) {

            plVar9 = (longlong *)plVar5[7];

          }

          plVar5[9] = 0;

          *(undefined1 *)plVar9 = 0;

          *(undefined1 *)(plVar5 + 0xd) = 0;

          uVar6 = (**(code **)(*plVar5 + 0x10))(plVar5,pcVar4,param_3,param_4);

          uVar10 = 0;

          if (plVar5[9] != 0) {

            do {

              plVar9 = plVar5 + 7;

              if (0xf < (ulonglong)plVar5[10]) {

                plVar9 = (longlong *)plVar5[7];

              }

              bVar1 = *(byte *)(uVar10 + (longlong)plVar9);

              iVar2 = isspace((uint)bVar1);

              if (((iVar2 == 0) && (bVar1 != 10)) && (bVar1 != 0xd)) {

                FUN_140025120(param_1,plVar5);

                goto LAB_14002aa30;

              }

              uVar10 = (ulonglong)((int)uVar10 + 1);

            } while (uVar10 < (ulonglong)plVar5[9]);

          }

          (**(code **)*plVar5)(plVar5,1);

        }

LAB_14002aa30:

        pcVar4 = (char *)FUN_140028820(uVar6,param_4);

      } while( true );

    }

    lVar3 = (**(code **)(*plVar9 + 0x20))(plVar9);

    if (lVar3 != 0) {

      lVar7 = (**(code **)(*plVar9 + 0x20))(plVar9);

      goto LAB_14002a88e;

    }

    plVar9 = (longlong *)plVar9[3];

  } while( true );

}




