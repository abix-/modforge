// Address: 0x140130c90
// Ghidra name: FUN_140130c90
// ============ 0x140130c90 FUN_140130c90 (size=613) ============


longlong *

FUN_140130c90(undefined8 param_1,undefined4 param_2,int param_3,undefined8 param_4,longlong param_5)



{

  void *_Buf1;

  void *_Buf2;

  char cVar1;

  int iVar2;

  int iVar3;

  undefined4 uVar4;

  longlong *plVar5;

  longlong lVar6;

  undefined4 *puVar7;

  ulonglong uVar8;

  int iVar9;

  

  uVar8 = (ulonglong)param_3;

  FUN_14017caa0(DAT_1403fb628);

  iVar2 = FUN_140138fe0(&DAT_1403fb654);

  FUN_14017cae0(DAT_1403fb628);

  if ((iVar2 == 0) && (plVar5 = (longlong *)FUN_1401841a0(1,0x1d8), plVar5 != (longlong *)0x0)) {

    lVar6 = FUN_14012f0d0(param_1);

    plVar5[1] = lVar6;

    if (lVar6 != 0) {

      *(undefined4 *)(plVar5 + 2) = param_2;

      lVar6 = FUN_140179a30();

      *plVar5 = lVar6;

      if (lVar6 != 0) {

        lVar6 = FUN_1401841a0((longlong)(param_3 + 1),0x18);

        plVar5[6] = lVar6;

        if (lVar6 != 0) {

          if (0 < param_3) {

            FUN_1402f8e20(lVar6,param_4,uVar8 * 0x18);

            FUN_140190720(plVar5[6],uVar8,0x18,FUN_140130230);

            iVar2 = 0;

            iVar9 = 1;

            do {

              _Buf1 = (void *)(plVar5[6] + (longlong)iVar2 * 0x18);

              _Buf2 = (void *)(plVar5[6] + (longlong)iVar9 * 0x18);

              iVar3 = memcmp(_Buf1,_Buf2,0x18);

              if (iVar3 == 0) {

                FUN_1402f8e20(_Buf1,_Buf2,(longlong)((int)uVar8 - iVar2) * 0x18);

                iVar2 = iVar2 + -1;

                iVar9 = iVar9 + -1;

                uVar8 = (ulonglong)((int)uVar8 - 1);

              }

              iVar2 = iVar2 + 1;

              iVar9 = iVar9 + 1;

              param_3 = (int)uVar8;

            } while (iVar2 < param_3);

          }

          plVar5[0xe] = param_5;

          *(int *)(plVar5 + 7) = param_3;

          uVar4 = FUN_1401aa810();

          *(undefined4 *)((longlong)plVar5 + 0x6c) = uVar4;

          FUN_140139010(plVar5 + 0x37,0);

          FUN_140139010((longlong)plVar5 + 0x1bc,0);

          FUN_140130b60(plVar5);

          FUN_14017cab0(DAT_1403fb628);

          cVar1 = FUN_1401ab100(DAT_1403fb630,*(undefined4 *)((longlong)plVar5 + 0x6c),plVar5,0);

          if (cVar1 == '\0') {

            FUN_140179b30(*plVar5);

            FUN_1401841e0(plVar5[6]);

            FUN_1401841e0(plVar5[1]);

            FUN_1401841e0(plVar5);

            plVar5 = (longlong *)0x0;

          }

          else {

            FUN_140138fb0(&DAT_1403fb650,1);

            puVar7 = (undefined4 *)FUN_1401841f0(0x10);

            if (puVar7 != (undefined4 *)0x0) {

              *puVar7 = 0x1400;

              puVar7[1] = *(undefined4 *)((longlong)plVar5 + 0x6c);

              *(undefined8 *)(puVar7 + 2) = 0;

              *(undefined4 **)((longlong)DAT_1403fb648 + 8) = puVar7;

              DAT_1403fb648 = puVar7;

              FUN_14017cae0(DAT_1403fb628);

              return plVar5;

            }

          }

          FUN_14017cae0(DAT_1403fb628);

          return plVar5;

        }

        FUN_140179b30(*plVar5);

      }

      FUN_1401841e0(plVar5[1]);

    }

    FUN_1401841e0(plVar5);

  }

  return (longlong *)0x0;

}




