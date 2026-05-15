// Address: 0x140206f60
// Ghidra name: FUN_140206f60
// ============ 0x140206f60 FUN_140206f60 (size=870) ============


longlong * FUN_140206f60(longlong *param_1,int param_2,longlong param_3)



{

  undefined8 *puVar1;

  longlong *plVar2;

  undefined4 uVar3;

  longlong *plVar4;

  longlong lVar5;

  char *pcVar6;

  undefined4 *puVar7;

  undefined8 uVar8;

  undefined *puVar9;

  undefined *puVar10;

  longlong *plVar11;

  char local_res20 [8];

  undefined4 in_stack_ffffffffffffff58;

  undefined2 uVar12;

  longlong lVar13;

  undefined4 uVar14;

  undefined8 uVar15;

  undefined4 uVar16;

  uint in_stack_ffffffffffffff78;

  undefined1 local_38 [16];

  

  uVar12 = (undefined2)((uint)in_stack_ffffffffffffff58 >> 0x10);

  _guard_check_icall();

  plVar11 = (longlong *)0x0;

  plVar2 = plVar11;

  for (plVar4 = DAT_1403fd198; plVar4 != (longlong *)0x0; plVar4 = (longlong *)plVar4[0x17]) {

    plVar2 = plVar4;

  }

  plVar4 = (longlong *)FUN_1401841a0(1,0xc0);

  if (plVar4 != (longlong *)0x0) {

    FUN_1401aa9d0(plVar4,9,1);

    if (*param_1 != 0) {

      lVar5 = FUN_14012f0d0();

      plVar4[3] = lVar5;

    }

    *(undefined1 *)(plVar4 + 0x13) = 1;

    *(short *)(plVar4 + 4) = (short)param_1[1];

    *(undefined2 *)((longlong)plVar4 + 0x22) = *(undefined2 *)((longlong)param_1 + 10);

    *(short *)((longlong)plVar4 + 0x24) = (short)param_1[3];

    *(undefined4 *)(plVar4 + 8) = *(undefined4 *)((longlong)param_1 + 0x34);

    *(int *)((longlong)plVar4 + 0x44) = (int)param_1[7];

    *(undefined4 *)(plVar4 + 9) = *(undefined4 *)((longlong)param_1 + 0x3c);

    *(int *)((longlong)plVar4 + 0x4c) = (int)param_1[8];

    *(short *)(plVar4 + 10) = (short)param_1[6];

    *(undefined2 *)((longlong)plVar4 + 0x52) = *(undefined2 *)((longlong)param_1 + 0x32);

    *(bool *)((longlong)plVar4 + 0x54) = *(int *)((longlong)param_1 + 0x44) == 2;

    lVar5 = FUN_140179a30();

    plVar4[0xf] = lVar5;

    pcVar6 = (char *)FUN_1402073f0(param_1[2]);

    lVar5 = FUN_1402073f0(param_1[4]);

    plVar4[1] = lVar5;

    lVar5 = FUN_1402073f0(param_1[5]);

    plVar4[2] = lVar5;

    lVar5 = FUN_1401578c0((short)plVar4[4],*(undefined2 *)((longlong)plVar4 + 0x22),plVar4[1],lVar5)

    ;

    *plVar4 = lVar5;

    if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) {

      FUN_1401841e0(pcVar6);

    }

    else {

      plVar4[5] = (longlong)pcVar6;

    }

    if (*plVar4 == 0) {

      FUN_1401841e0(plVar4[1]);

      FUN_1401841e0(plVar4[2]);

      FUN_1401841e0(plVar4[5]);

      FUN_1401841e0(plVar4[3]);

      FUN_1401841e0(plVar4);

    }

    else {

      uVar8 = 5;

      if (*(int *)((longlong)param_1 + 0x44) != 2) {

        uVar8 = 3;

      }

      lVar5 = plVar4[2];

      lVar13 = plVar4[1];

      puVar7 = (undefined4 *)

               FUN_140157780(local_38,uVar8,(short)plVar4[4],

                             *(undefined2 *)((longlong)plVar4 + 0x22),

                             CONCAT22(uVar12,*(undefined2 *)((longlong)plVar4 + 0x24)),lVar13,lVar5,

                             0x68,in_stack_ffffffffffffff78 & 0xffffff00);

      uVar3 = puVar7[1];

      uVar14 = puVar7[2];

      uVar16 = puVar7[3];

      uVar15 = CONCAT44((int)((ulonglong)lVar5 >> 0x20),*(undefined4 *)((longlong)plVar4 + 0x4c));

      uVar8 = CONCAT44((int)((ulonglong)lVar13 >> 0x20),(int)plVar4[9]);

      *(undefined4 *)(plVar4 + 6) = *puVar7;

      *(undefined4 *)((longlong)plVar4 + 0x34) = uVar3;

      *(undefined4 *)(plVar4 + 7) = uVar14;

      *(undefined4 *)((longlong)plVar4 + 0x3c) = uVar16;

      *(undefined4 *)(plVar4 + 0xb) = 1;

      uVar3 = FUN_140208c00(*plVar4,(short)plVar4[4],*(undefined2 *)((longlong)plVar4 + 0x22),

                            (int)plVar4[8],*(undefined4 *)((longlong)plVar4 + 0x44),uVar8,uVar15);

      uVar14 = (undefined4)((ulonglong)uVar8 >> 0x20);

      uVar16 = (undefined4)((ulonglong)uVar15 >> 0x20);

      *(undefined4 *)((longlong)plVar4 + 0x5c) = uVar3;

      *(undefined4 *)(plVar4 + 0xc) = 0xffffffff;

      if (0 < param_2) {

        *(int *)(plVar4 + 0x15) = param_2;

        plVar4[0x16] = param_3;

        do {

          lVar5 = (longlong)plVar11 * 8;

          plVar11 = (longlong *)((longlong)plVar11 + 1);

          *(longlong **)(*(longlong *)(param_3 + lVar5) + 0xa0) = plVar4;

        } while ((longlong)plVar11 < (longlong)param_2);

      }

      plVar11 = plVar4;

      if (plVar2 != (longlong *)0x0) {

        plVar2[0x17] = (longlong)plVar4;

        plVar11 = DAT_1403fd198;

      }

      DAT_1403fd198 = plVar11;

      local_res20[0] = '\0';

      FUN_140208550(plVar4,local_res20);

      if (local_res20[0] == '\0') {

        puVar1 = (undefined8 *)plVar4[0xd];

        if ((puVar1 == (undefined8 *)0x0) || (*(char *)(puVar1 + 1) == '\0')) {

          pcVar6 = "DISABLED";

          if (puVar1 == (undefined8 *)0x0) {

            puVar9 = &DAT_14034fbc0;

          }

          else {

            puVar9 = (undefined *)*puVar1;

          }

        }

        else {

          puVar9 = (undefined *)*puVar1;

          pcVar6 = "ENABLED";

        }

        puVar10 = &DAT_14034fbc0;

        if ((undefined *)plVar4[5] != (undefined *)0x0) {

          puVar10 = (undefined *)plVar4[5];

        }

        FUN_14012e080(7,

                      "Added HIDAPI device \'%s\' VID 0x%.4x, PID 0x%.4x, bluetooth %d, version %d, serial %s, interface %d, interface_class %d, interface_subclass %d, interface_protocol %d, usage page 0x%.4x, usage 0x%.4x, path = %s, driver = %s (%s)"

                      ,*plVar4,(short)plVar4[4],*(undefined2 *)((longlong)plVar4 + 0x22),

                      CONCAT44(uVar14,(uint)*(byte *)((longlong)plVar4 + 0x54)),

                      CONCAT44(uVar16,(uint)*(ushort *)((longlong)plVar4 + 0x24)),puVar10,

                      (int)plVar4[8],*(undefined4 *)((longlong)plVar4 + 0x44),(int)plVar4[9],

                      *(undefined4 *)((longlong)plVar4 + 0x4c),(short)plVar4[10],

                      *(undefined2 *)((longlong)plVar4 + 0x52),plVar4[3],puVar9,pcVar6);

        return plVar4;

      }

    }

  }

  return (longlong *)0x0;

}




