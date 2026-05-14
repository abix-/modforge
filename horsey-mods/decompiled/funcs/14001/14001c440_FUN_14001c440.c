// Address: 0x14001c440
// Ghidra name: FUN_14001c440
// ============ 0x14001c440 FUN_14001c440 (size=1038) ============


void FUN_14001c440(longlong param_1,longlong param_2)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  float fVar20;

  float fVar21;

  float fVar22;

  float fVar23;

  float fVar24;

  int iVar25;

  longlong lVar26;

  longlong lVar27;

  longlong lVar28;

  longlong lVar29;

  float fVar30;

  float fVar31;

  float fVar32;

  float fVar33;

  float fVar34;

  

  lVar26 = *(longlong *)(param_2 + 0x20);

  fVar1 = *(float *)(param_1 + 0x140);

  fVar2 = *(float *)(param_1 + 0x144);

  fVar3 = *(float *)(param_1 + 0x13c);

  fVar4 = *(float *)(param_1 + 0x148);

  lVar27 = (longlong)*(int *)(param_1 + 0xdc);

  fVar5 = *(float *)(param_1 + 300);

  lVar28 = (longlong)*(int *)(param_1 + 0xe0);

  fVar6 = *(float *)(lVar26 + lVar27 * 0xc);

  fVar7 = *(float *)(lVar26 + 4 + lVar27 * 0xc);

  fVar8 = *(float *)(lVar26 + 8 + lVar27 * 0xc);

  lVar29 = (longlong)*(int *)(param_1 + 0xe4);

  fVar9 = *(float *)(lVar26 + 4 + lVar28 * 0xc);

  fVar10 = *(float *)(lVar26 + lVar28 * 0xc);

  fVar11 = *(float *)(lVar26 + 8 + lVar28 * 0xc);

  fVar12 = *(float *)(lVar26 + lVar29 * 0xc);

  fVar13 = *(float *)(lVar26 + 4 + lVar29 * 0xc);

  fVar14 = *(float *)(lVar26 + 8 + lVar29 * 0xc);

  lVar28 = (longlong)*(int *)(param_1 + 0xe8);

  fVar15 = *(float *)(lVar26 + lVar28 * 0xc);

  fVar16 = *(float *)(lVar26 + 4 + lVar28 * 0xc);

  fVar17 = *(float *)(lVar26 + 8 + lVar28 * 0xc);

  fVar18 = *(float *)(param_1 + 0x134);

  fVar34 = ((fVar9 - fVar16) * *(float *)(param_1 + 0x138) + (fVar10 - fVar15) * fVar18 +

            (fVar7 - fVar13) * *(float *)(param_1 + 0x130) + (fVar6 - fVar12) * fVar5 +

           (fVar11 * fVar1 - fVar17 * fVar4) + (fVar8 * fVar3 - fVar14 * fVar2)) *

           (float)(*(uint *)(param_1 + 0x14c) ^ DAT_14039cac0);

  *(float *)(param_1 + 0xd8) = fVar34 + *(float *)(param_1 + 0xd8);

  fVar30 = fVar34 * *(float *)(param_1 + 0x10c);

  lVar26 = *(longlong *)(param_2 + 0x20);

  fVar19 = *(float *)(param_1 + 0x124);

  fVar20 = *(float *)(param_1 + 0x11c);

  fVar21 = *(float *)(param_1 + 0x130);

  fVar22 = *(float *)(param_1 + 0x138);

  fVar33 = fVar34 * *(float *)(param_1 + 0x118);

  fVar31 = fVar34 * *(float *)(param_1 + 0x110);

  fVar23 = *(float *)(param_1 + 0x120);

  fVar32 = fVar34 * *(float *)(param_1 + 0x114);

  fVar24 = *(float *)(param_1 + 0x128);

  *(float *)(lVar26 + lVar27 * 0xc) = fVar5 * fVar30 + fVar6;

  *(float *)(lVar26 + 4 + lVar27 * 0xc) = fVar21 * fVar30 + fVar7;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xdc) * 0xc) =

       fVar34 * fVar20 * fVar3 + fVar8;

  iVar25 = *(int *)(param_1 + 0xe0);

  lVar26 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar26 + (longlong)iVar25 * 0xc) = fVar18 * fVar31 + fVar10;

  *(float *)(lVar26 + 4 + (longlong)iVar25 * 0xc) = fVar22 * fVar31 + fVar9;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xe0) * 0xc) =

       fVar34 * fVar23 * fVar1 + fVar11;

  iVar25 = *(int *)(param_1 + 0xe4);

  lVar26 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar26 + (longlong)iVar25 * 0xc) = fVar12 - fVar5 * fVar32;

  *(float *)(lVar26 + 4 + (longlong)iVar25 * 0xc) = fVar13 - fVar32 * fVar21;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xe4) * 0xc) =

       fVar14 - fVar34 * fVar19 * fVar2;

  iVar25 = *(int *)(param_1 + 0xe8);

  lVar26 = *(longlong *)(param_2 + 0x20);

  *(float *)(lVar26 + (longlong)iVar25 * 0xc) = fVar15 - fVar18 * fVar33;

  *(float *)(lVar26 + 4 + (longlong)iVar25 * 0xc) = fVar16 - fVar33 * fVar22;

  *(float *)(*(longlong *)(param_2 + 0x20) + 8 + (longlong)*(int *)(param_1 + 0xe8) * 0xc) =

       fVar17 - fVar34 * fVar24 * fVar4;

  return;

}




