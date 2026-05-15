// Address: 0x140221a50
// Ghidra name: FUN_140221a50
// ============ 0x140221a50 FUN_140221a50 (size=335) ============


/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



char * FUN_140221a50(longlong param_1,undefined8 param_2,longlong param_3,longlong *param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  code *pcVar3;

  uint uVar4;

  undefined4 uVar5;

  longlong lVar6;

  ulonglong uVar7;

  ulonglong uVar8;

  char *pcVar9;

  ulonglong uVar10;

  int iVar11;

  undefined4 *puVar12;

  char *pcVar13;

  undefined4 *puVar14;

  longlong lVar15;

  int iVar16;

  int local_res8 [2];

  undefined8 auStack_70 [5];

  undefined1 auStack_48 [16];

  

  lVar15 = *(longlong *)(param_1 + 0x30);

  auStack_70[0] = 0x140221a7c;

  lVar6 = (**(code **)(*param_4 + 0x28))(param_4);

  uVar1 = *(undefined4 *)(param_3 + 0x18);

  lVar15 = (lVar6 + lVar15) * 1000;

  uVar10 = (ulonglong)*(uint *)(*(longlong *)(*(longlong *)(param_3 + 8) + 0xd0) + 0x10);

  uVar7 = uVar10 * 0xc;

  uVar8 = uVar7 + 0xf;

  if (uVar8 <= uVar7) {

    uVar8 = 0xffffffffffffff0;

  }

  pcVar9 = (char *)(uVar8 & 0xfffffffffffffff0);

  auStack_70[0] = 0x140221ac3;

  lVar6 = -(longlong)pcVar9;

  puVar12 = (undefined4 *)(&stack0xffffffffffffffc8 + lVar6);

  if (puVar12 != (undefined4 *)0x0) {

    pcVar3 = *(code **)(*param_4 + 0x78);

    *(undefined8 *)((longlong)auStack_70 + lVar6) = 0x140221ae0;

    uVar4 = (*pcVar3)(param_4,uVar10,puVar12);

    uVar8 = (ulonglong)uVar4;

    if (uVar4 == 0) {

      *(undefined8 *)((longlong)auStack_70 + lVar6) = 0x140221aec;

      pcVar9 = (char *)FUN_1401837c0();

    }

    else {

      *(undefined8 *)((longlong)auStack_70 + lVar6) = 0x140221afa;

      pcVar9 = (char *)FUN_140183330(local_res8);

      iVar11 = 0;

      pcVar13 = pcVar9;

      puVar14 = puVar12;

      iVar16 = local_res8[0];

      if (0 < local_res8[0]) {

        do {

          if (*pcVar13 != '\0') {

            *(undefined8 *)((longlong)auStack_70 + lVar6) = 0x140221b23;

            pcVar9 = (char *)FUN_140221f60(puVar12,uVar8,iVar11);

            if ((char)pcVar9 == '\0') {

              uVar2 = *puVar14;

              auStack_48[lVar6] = 0;

              *(undefined8 *)((longlong)auStack_70 + lVar6) = 0x140221b3c;

              pcVar9 = (char *)FUN_140183990(lVar15,uVar1,uVar2,iVar11);

              iVar16 = local_res8[0];

            }

          }

          iVar11 = iVar11 + 1;

          pcVar13 = pcVar13 + 1;

          puVar14 = puVar14 + 3;

        } while (iVar11 < iVar16);

      }

      puVar14 = puVar12;

      if (uVar4 != 0) {

        do {

          *(undefined8 *)((longlong)auStack_70 + lVar6) = 0x140221b68;

          uVar5 = FUN_140221f30(puVar12);

          uVar2 = *puVar14;

          auStack_48[lVar6] = 1;

          *(undefined8 *)((longlong)auStack_70 + lVar6) = 0x140221b7e;

          pcVar9 = (char *)FUN_140183990(lVar15,uVar1,uVar2,uVar5);

          puVar12 = puVar12 + 3;

          uVar8 = uVar8 - 1;

          puVar14 = puVar14 + 3;

        } while (uVar8 != 0);

      }

    }

  }

  return pcVar9;

}




