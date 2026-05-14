// Address: 0x1401a71d0
// Ghidra name: FUN_1401a71d0
// ============ 0x1401a71d0 FUN_1401a71d0 (size=380) ============


uint * FUN_1401a71d0(uint param_1,uint *param_2,uint *param_3)



{

  int iVar1;

  uint uVar2;

  uint *puVar3;

  uint uVar4;

  longlong lVar5;

  byte bVar6;

  uint uVar7;

  ulonglong uVar8;

  longlong lVar9;

  uint uVar10;

  undefined1 auStack_c28 [32];

  uint local_c08 [248];

  int aiStack_828 [8];

  uint local_808 [256];

  uint auStack_408 [256];

  

  FUN_1402f94c0(local_808,0);

  uVar2 = 2;

  if (param_1 != 0) {

    uVar8 = (ulonglong)param_1;

    puVar3 = param_2;

    do {

      uVar2 = *puVar3;

      puVar3 = puVar3 + 1;

      local_808[(ulonglong)(ushort)uVar2 & 0xff] = local_808[(ulonglong)(ushort)uVar2 & 0xff] + 1;

      local_808[(ushort)((ushort)uVar2 >> 8) + 0x100] =

           local_808[(ushort)((ushort)uVar2 >> 8) + 0x100] + 1;

      uVar8 = uVar8 - 1;

      uVar2 = 2;

    } while (uVar8 != 0);

  }

  do {

    uVar10 = uVar2;

    uVar2 = uVar10 - 1;

    if (param_1 != local_808[uVar2 * 0x100]) break;

  } while (1 < uVar2);

  if (param_1 != local_808[uVar2 * 0x100]) {

    uVar2 = uVar10;

  }

  bVar6 = 0;

  uVar10 = 0;

  puVar3 = param_2;

  if (uVar2 != 0) {

    do {

      param_2 = param_3;

      param_3 = puVar3;

      lVar5 = (ulonglong)(uVar10 << 8) * 4 + (-0x828 - (longlong)auStack_c28);

      uVar7 = 0;

      lVar9 = 0x80;

      puVar3 = local_c08;

      do {

        iVar1 = *(int *)((longlong)aiStack_828 + lVar5 + 0x828 + (longlong)puVar3);

        *puVar3 = uVar7;

        uVar4 = iVar1 + uVar7;

        uVar7 = *(int *)((longlong)local_c08 + lVar5 + 0xc04 + (longlong)(puVar3 + 2)) + uVar4;

        puVar3[1] = uVar4;

        lVar9 = lVar9 + -1;

        puVar3 = puVar3 + 2;

      } while (lVar9 != 0);

      puVar3 = param_3;

      uVar8 = (ulonglong)param_1;

      if (param_1 != 0) {

        do {

          param_2[local_c08[(byte)((*puVar3 & 0xffff) >> (bVar6 & 0x3f))]] = *puVar3;

          local_c08[(byte)((ushort)*puVar3 >> (bVar6 & 0x3f))] =

               local_c08[(byte)((ushort)*puVar3 >> (bVar6 & 0x3f))] + 1;

          uVar8 = uVar8 - 1;

          puVar3 = puVar3 + 1;

        } while (uVar8 != 0);

      }

      uVar10 = uVar10 + 1;

      bVar6 = bVar6 + 8;

      puVar3 = param_2;

    } while (uVar10 < uVar2);

  }

  return param_2;

}




