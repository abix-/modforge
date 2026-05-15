// Address: 0x140227cc0
// Ghidra name: FUN_140227cc0
// ============ 0x140227cc0 FUN_140227cc0 (size=788) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



HICON FUN_140227cc0(longlong *param_1,int param_2,undefined4 param_3,undefined4 param_4,

                   float param_5)



{

  double dVar1;

  byte bVar2;

  byte bVar3;

  byte bVar4;

  byte bVar5;

  byte bVar6;

  byte bVar7;

  byte bVar8;

  undefined4 uVar9;

  DWORD dwResSize;

  longlong lVar10;

  undefined8 uVar11;

  longlong lVar12;

  undefined8 uVar13;

  PBYTE presbits;

  HICON pHVar14;

  uint *puVar15;

  longlong lVar16;

  float fVar17;

  float fVar18;

  undefined4 local_70;

  int local_6c;

  int local_68;

  undefined8 local_64;

  undefined8 uStack_5c;

  undefined4 local_54;

  undefined4 local_50;

  

  lVar16 = (longlong)param_2;

  pHVar14 = (HICON)0x0;

  lVar10 = FUN_14012c080();

  if (lVar10 != 0) {

    fVar17 = (float)thunk_FUN_1402e1d00((float)*(int *)(*param_1 + 8) * param_5);

    fVar18 = (float)thunk_FUN_1402e1d00((float)*(int *)(*param_1 + 0xc) * param_5);

    bVar2 = FUN_14012cd80(lVar10,0x46464952);

    uVar11 = FUN_14012cba0(lVar10);

    bVar3 = FUN_14012cd80(lVar10,0);

    bVar4 = FUN_14012cd80(lVar10,0x4e4f4341);

    bVar5 = FUN_14012cd80(lVar10,0x68696e61);

    bVar6 = FUN_14012cd80(lVar10,0x24);

    local_70 = 0x24;

    local_54 = 1;

    local_50 = 1;

    local_64 = 0;

    uStack_5c = 0;

    local_6c = param_2;

    local_68 = param_2;

    lVar12 = FUN_14012cbb0(lVar10,&local_70,0x24);

    bVar7 = FUN_14012cd80(lVar10,0x65746172);

    bVar8 = FUN_14012cd80(lVar10,param_2 * 4);

    dVar1 = _DAT_140356de0;

    bVar2 = bVar8 & lVar12 == 0x24 & bVar7 & bVar6 & bVar5 & bVar4 & bVar3 & bVar2;

    if (0 < lVar16) {

      puVar15 = (uint *)(param_1 + 1);

      lVar12 = lVar16;

      do {

        if (*puVar15 == 0) {

          uVar9 = 0xffffffff;

        }

        else {

          uVar9 = thunk_FUN_1402e1c90((double)*puVar15 / dVar1);

        }

        bVar3 = FUN_14012cd80(lVar10,uVar9);

        bVar2 = bVar2 & bVar3;

        puVar15 = puVar15 + 4;

        lVar12 = lVar12 + -1;

      } while (lVar12 != 0);

    }

    bVar3 = FUN_14012cd80(lVar10,0x5453494c);

    uVar13 = FUN_14012cba0(lVar10);

    bVar4 = FUN_14012cd80(lVar10,0);

    bVar5 = FUN_14012cd80(lVar10,0x6d617266);

    bVar4 = bVar5 & (bVar3 & bVar2) != 0 & bVar4;

    if (0 < lVar16) {

      do {

        bVar2 = FUN_140228760(lVar10,*param_1,param_3,param_4,param_5);

        bVar4 = bVar4 & bVar2;

        param_1 = param_1 + 2;

        lVar16 = lVar16 + -1;

      } while (lVar16 != 0);

    }

    bVar2 = FUN_1402278c0(lVar10,uVar13);

    bVar3 = FUN_1402278c0(lVar10,uVar11);

    if (((bVar4 & bVar2) != 0 & bVar3) != 0) {

      uVar9 = FUN_14012be20(lVar10);

      presbits = (PBYTE)FUN_140174d30(uVar9,"SDL.iostream.dynamic.memory",0);

      dwResSize = FUN_14012be60(lVar10);

      pHVar14 = CreateIconFromResourceEx(presbits,dwResSize,0,0x30000,(int)fVar17,(int)fVar18,0);

      if (pHVar14 == (HICON)0x0) {

        FUN_14012e850("CreateIconFromResource failed");

      }

    }

    FUN_14012bd50(lVar10);

    return pHVar14;

  }

  return (HICON)0x0;

}




