// Address: 0x14020fe40
// Ghidra name: FUN_14020fe40
// ============ 0x14020fe40 FUN_14020fe40 (size=501) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



ulonglong FUN_14020fe40(longlong param_1,longlong *param_2,undefined8 param_3)



{

  float fVar1;

  undefined1 uVar2;

  undefined4 uVar3;

  code *pcVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  float fVar8;

  float fVar9;

  uint uVar10;

  ulonglong uVar11;

  ulonglong uVar12;

  ulonglong uVar13;

  uint uVar14;

  uint uVar15;

  undefined4 *puVar16;

  undefined8 uVar17;

  float *pfVar18;

  undefined1 *puVar19;

  undefined8 auStack_80 [5];

  float local_58 [8];

  

  uVar13 = (ulonglong)*(int *)(param_1 + 0x70);

  uVar12 = uVar13 + 0xf;

  if (uVar12 <= uVar13) {

    uVar12 = 0xffffffffffffff0;

  }

  auStack_80[0] = 0x14020fe94;

  lVar5 = -(uVar12 & 0xfffffffffffffff0);

  uVar11 = (longlong)*(int *)(param_1 + 0x44) * 4;

  puVar19 = (undefined1 *)((longlong)local_58 + lVar5);

  uVar12 = uVar11 + 0xf;

  if (uVar12 <= uVar11) {

    uVar12 = 0xffffffffffffff0;

  }

  *(undefined8 *)((longlong)auStack_80 + lVar5) = 0x14020febc;

  lVar6 = -(uVar12 & 0xfffffffffffffff0);

  uVar11 = (longlong)*(int *)(param_1 + 0x60) * 4;

  pfVar18 = (float *)((longlong)local_58 + lVar6 + lVar5);

  uVar12 = uVar11 + 0xf;

  if (uVar12 <= uVar11) {

    uVar12 = 0xffffffffffffff0;

  }

  uVar12 = uVar12 & 0xfffffffffffffff0;

  *(undefined8 *)((longlong)auStack_80 + lVar6 + lVar5) = 0x14020fee4;

  lVar7 = -uVar12;

  uVar14 = 0;

  puVar16 = (undefined4 *)((longlong)local_58 + lVar7 + lVar6 + lVar5);

  if (puVar19 != (undefined1 *)0x0) {

    pcVar4 = *(code **)(*param_2 + 0x58);

    *(undefined8 *)((longlong)auStack_80 + lVar7 + lVar6 + lVar5) = 0x14020ff03;

    uVar12 = (*pcVar4)(param_2,uVar13,puVar19);

    uVar10 = (uint)uVar12;

    uVar15 = uVar14;

    if (uVar10 != 0) {

      do {

        uVar2 = *puVar19;

        *(undefined8 *)((longlong)auStack_80 + lVar7 + lVar6 + lVar5) = 0x14020ff23;

        uVar12 = FUN_14015ad00(param_3,param_1,uVar15 & 0xff,uVar2);

        uVar15 = uVar15 + 1;

        puVar19 = puVar19 + 1;

      } while (uVar15 < uVar10);

    }

  }

  if (pfVar18 != (float *)0x0) {

    uVar3 = *(undefined4 *)(param_1 + 0x44);

    pcVar4 = *(code **)(*param_2 + 0x48);

    *(undefined8 *)((longlong)auStack_80 + lVar7 + lVar6 + lVar5) = 0x14020ff4a;

    uVar12 = (*pcVar4)(param_2,uVar3,pfVar18);

    fVar9 = _DAT_140350d1c;

    fVar8 = DAT_14030ec38;

    uVar10 = (uint)uVar12;

    uVar15 = uVar14;

    if (uVar10 != 0) {

      do {

        fVar1 = *pfVar18;

        *(undefined8 *)((longlong)auStack_80 + lVar7 + lVar6 + lVar5) = 0x14020ff92;

        uVar12 = FUN_14015aab0(param_3,param_1,uVar15 & 0xff,(int)(fVar1 * fVar8 - fVar9));

        uVar15 = uVar15 + 1;

        pfVar18 = pfVar18 + 1;

      } while (uVar15 < uVar10);

    }

  }

  if (puVar16 != (undefined4 *)0x0) {

    uVar3 = *(undefined4 *)(param_1 + 0x60);

    pcVar4 = *(code **)(*param_2 + 0x68);

    *(undefined8 *)((longlong)auStack_80 + lVar7 + lVar6 + lVar5) = 0x14020ffb3;

    uVar12 = (*pcVar4)(param_2,uVar3,puVar16);

    uVar15 = (uint)uVar12;

    if (uVar15 != 0) {

      do {

        switch(*puVar16) {

        default:

          uVar17 = 0;

          break;

        case 1:

          uVar17 = 1;

          break;

        case 2:

          uVar17 = 3;

          break;

        case 3:

          uVar17 = 2;

          break;

        case 4:

          uVar17 = 6;

          break;

        case 5:

          uVar17 = 4;

          break;

        case 6:

          uVar17 = 0xc;

          break;

        case 7:

          uVar17 = 8;

          break;

        case 8:

          uVar17 = 9;

        }

        *(undefined8 *)((longlong)auStack_80 + lVar7 + lVar6 + lVar5) = 0x14021000f;

        uVar12 = FUN_14015ae90(param_3,param_1,uVar14 & 0xff,uVar17);

        uVar14 = uVar14 + 1;

        puVar16 = puVar16 + 1;

      } while (uVar14 < uVar15);

    }

  }

  return uVar12;

}




