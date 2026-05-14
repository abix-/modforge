// Address: 0x14003efb0
// Ghidra name: FUN_14003efb0
// ============ 0x14003efb0 FUN_14003efb0 (size=602) ============


void FUN_14003efb0(void)



{

  char cVar1;

  undefined8 *puVar2;

  longlong *plVar3;

  undefined8 *puVar4;

  longlong *plVar5;

  undefined8 *puVar6;

  undefined8 *puVar7;

  longlong *plVar8;

  ulonglong uVar9;

  undefined8 *puVar10;

  undefined1 local_60 [32];

  undefined8 *local_40;

  undefined8 *puStack_38;

  undefined8 *local_30;

  

  if (DAT_1403ea293 != '\0') {

    plVar8 = (longlong *)*DAT_1403ea2c0;

    cVar1 = *(char *)((longlong)plVar8 + 0x19);

    while (cVar1 == '\0') {

      FUN_1400279c0(local_60,plVar8 + 4);

      local_40 = (undefined8 *)0x0;

      puStack_38 = (undefined8 *)0x0;

      local_30 = (undefined8 *)0x0;

      uVar9 = plVar8[9] - plVar8[8] >> 6;

      puVar4 = local_40;

      puVar7 = puStack_38;

      puVar6 = puStack_38;

      if (uVar9 != 0) {

        if (0x3ffffffffffffff < uVar9) {

                    /* WARNING: Subroutine does not return */

          FUN_14002f0d0();

        }

        puVar7 = (undefined8 *)FUN_1400285e0();

        local_30 = puVar7 + uVar9 * 8;

        puVar2 = (undefined8 *)plVar8[9];

        local_40 = puVar7;

        puStack_38 = puVar7;

        for (puVar10 = (undefined8 *)plVar8[8]; puVar4 = local_40, puVar6 = puVar7,

            puVar10 != puVar2; puVar10 = puVar10 + 8) {

          *puVar7 = *puVar10;

          FUN_1400279c0(puVar7 + 1,puVar10 + 1);

          *(undefined4 *)(puVar7 + 5) = *(undefined4 *)(puVar10 + 5);

          *(undefined4 *)((longlong)puVar7 + 0x2c) = *(undefined4 *)((longlong)puVar10 + 0x2c);

          *(undefined4 *)(puVar7 + 6) = *(undefined4 *)(puVar10 + 6);

          *(undefined4 *)((longlong)puVar7 + 0x34) = *(undefined4 *)((longlong)puVar10 + 0x34);

          *(undefined1 *)(puVar7 + 7) = *(undefined1 *)(puVar10 + 7);

          puVar7 = puVar7 + 8;

        }

      }

      for (; puStack_38 = puVar6, puVar6 = puStack_38, puVar4 != puStack_38; puVar4 = puVar4 + 8) {

        puStack_38 = puVar7;

        if (*(char *)(puVar4 + 7) == '\0') {

          FUN_1400447e0();

        }

        puVar7 = puStack_38;

      }

      puStack_38 = puVar7;

      puVar4 = local_40;

      if (local_40 != (undefined8 *)0x0) {

        for (; puVar4 != puVar7; puVar4 = puVar4 + 8) {

          FUN_140027900();

        }

        puVar7 = local_40;

        if ((0xfff < ((longlong)local_30 - (longlong)local_40 & 0xffffffffffffffc0U)) &&

           (puVar7 = (undefined8 *)local_40[-1],

           0x1f < (ulonglong)((longlong)local_40 + (-8 - (longlong)puVar7)))) {

                    /* WARNING: Subroutine does not return */

          _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

        }

        FUN_1402c7088(puVar7);

        local_40 = (undefined8 *)0x0;

        puStack_38 = (undefined8 *)0x0;

        local_30 = (undefined8 *)0x0;

      }

      FUN_140027900(local_60);

      plVar3 = (longlong *)plVar8[2];

      if (*(char *)((longlong)plVar3 + 0x19) == '\0') {

        cVar1 = *(char *)(*plVar3 + 0x19);

        plVar8 = plVar3;

        plVar3 = (longlong *)*plVar3;

        while (cVar1 == '\0') {

          cVar1 = *(char *)(*plVar3 + 0x19);

          plVar8 = plVar3;

          plVar3 = (longlong *)*plVar3;

        }

      }

      else {

        cVar1 = *(char *)(plVar8[1] + 0x19);

        plVar5 = (longlong *)plVar8[1];

        plVar3 = plVar8;

        while ((plVar8 = plVar5, cVar1 == '\0' && (plVar3 == (longlong *)plVar8[2]))) {

          cVar1 = *(char *)(plVar8[1] + 0x19);

          plVar5 = (longlong *)plVar8[1];

          plVar3 = plVar8;

        }

      }

      cVar1 = *(char *)((longlong)plVar8 + 0x19);

    }

    DAT_1403ea293 = '\0';

  }

  return;

}




