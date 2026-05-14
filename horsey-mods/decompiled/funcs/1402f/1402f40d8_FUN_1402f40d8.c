// Address: 0x1402f40d8
// Ghidra name: FUN_1402f40d8
// ============ 0x1402f40d8 FUN_1402f40d8 (size=623) ============


int FUN_1402f40d8(int param_1,char param_2,__acrt_ptd *param_3,__crt_multibyte_data **param_4)



{

  int iVar1;

  undefined8 uVar2;

  int *piVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  undefined4 uVar9;

  undefined4 uVar10;

  undefined8 uVar11;

  undefined8 uVar12;

  undefined8 uVar13;

  undefined8 *puVar14;

  undefined8 *puVar15;

  int iVar16;

  undefined8 *puVar17;

  undefined8 *puVar18;

  undefined4 *puVar19;

  undefined8 *puVar20;

  longlong lVar21;

  longlong lVar22;

  __acrt_ptd *local_res18;

  __crt_multibyte_data **local_res20;

  undefined1 local_268 [4];

  undefined4 local_264;

  undefined4 local_260 [2];

  __acrt_ptd **local_258;

  __crt_multibyte_data ***local_250;

  undefined8 local_248 [70];

  

  local_res18 = param_3;

  local_res20 = param_4;

  update_thread_multibyte_data_internal(param_3,param_4);

  iVar16 = getSystemCP(param_1);

  if (iVar16 == *(int *)(*(longlong *)(local_res18 + 0x88) + 4)) {

    iVar16 = 0;

  }

  else {

    puVar17 = (undefined8 *)_malloc_base(0x228);

    if (puVar17 == (undefined8 *)0x0) {

      FUN_1402e9a80(0);

      iVar16 = -1;

    }

    else {

      lVar21 = 4;

      lVar22 = 4;

      puVar14 = *(undefined8 **)(local_res18 + 0x88);

      puVar15 = local_248;

      do {

        puVar20 = puVar15;

        puVar18 = puVar14;

        uVar2 = puVar18[1];

        uVar11 = puVar18[2];

        uVar12 = puVar18[3];

        *puVar20 = *puVar18;

        puVar20[1] = uVar2;

        uVar2 = puVar18[4];

        uVar13 = puVar18[5];

        puVar20[2] = uVar11;

        puVar20[3] = uVar12;

        uVar11 = puVar18[6];

        uVar12 = puVar18[7];

        puVar20[4] = uVar2;

        puVar20[5] = uVar13;

        uVar2 = puVar18[8];

        uVar13 = puVar18[9];

        puVar20[6] = uVar11;

        puVar20[7] = uVar12;

        uVar11 = puVar18[10];

        uVar12 = puVar18[0xb];

        puVar20[8] = uVar2;

        puVar20[9] = uVar13;

        uVar2 = puVar18[0xc];

        uVar13 = puVar18[0xd];

        puVar20[10] = uVar11;

        puVar20[0xb] = uVar12;

        uVar11 = puVar18[0xe];

        uVar12 = puVar18[0xf];

        puVar20[0xc] = uVar2;

        puVar20[0xd] = uVar13;

        puVar20[0xe] = uVar11;

        puVar20[0xf] = uVar12;

        lVar22 = lVar22 + -1;

        puVar14 = puVar18 + 0x10;

        puVar15 = puVar20 + 0x10;

      } while (lVar22 != 0);

      uVar11 = puVar18[0x11];

      uVar12 = puVar18[0x12];

      uVar13 = puVar18[0x13];

      uVar2 = puVar18[0x14];

      puVar20[0x10] = puVar18[0x10];

      puVar20[0x11] = uVar11;

      puVar20[0x12] = uVar12;

      puVar20[0x13] = uVar13;

      puVar20[0x14] = uVar2;

      puVar14 = local_248;

      puVar15 = puVar17;

      do {

        puVar20 = puVar15;

        puVar18 = puVar14;

        uVar2 = puVar18[1];

        uVar11 = puVar18[2];

        uVar12 = puVar18[3];

        *puVar20 = *puVar18;

        puVar20[1] = uVar2;

        uVar2 = puVar18[4];

        uVar13 = puVar18[5];

        puVar20[2] = uVar11;

        puVar20[3] = uVar12;

        uVar11 = puVar18[6];

        uVar12 = puVar18[7];

        puVar20[4] = uVar2;

        puVar20[5] = uVar13;

        uVar2 = puVar18[8];

        uVar13 = puVar18[9];

        puVar20[6] = uVar11;

        puVar20[7] = uVar12;

        uVar11 = puVar18[10];

        uVar12 = puVar18[0xb];

        puVar20[8] = uVar2;

        puVar20[9] = uVar13;

        uVar2 = puVar18[0xc];

        uVar13 = puVar18[0xd];

        puVar20[10] = uVar11;

        puVar20[0xb] = uVar12;

        uVar11 = puVar18[0xe];

        uVar12 = puVar18[0xf];

        puVar20[0xc] = uVar2;

        puVar20[0xd] = uVar13;

        puVar20[0xe] = uVar11;

        puVar20[0xf] = uVar12;

        lVar21 = lVar21 + -1;

        puVar14 = puVar18 + 0x10;

        puVar15 = puVar20 + 0x10;

      } while (lVar21 != 0);

      uVar4 = *(undefined4 *)((longlong)puVar18 + 0x84);

      uVar5 = *(undefined4 *)(puVar18 + 0x11);

      uVar6 = *(undefined4 *)((longlong)puVar18 + 0x8c);

      uVar7 = *(undefined4 *)(puVar18 + 0x12);

      uVar8 = *(undefined4 *)((longlong)puVar18 + 0x94);

      uVar9 = *(undefined4 *)(puVar18 + 0x13);

      uVar10 = *(undefined4 *)((longlong)puVar18 + 0x9c);

      uVar2 = puVar18[0x14];

      *(undefined4 *)(puVar20 + 0x10) = *(undefined4 *)(puVar18 + 0x10);

      *(undefined4 *)((longlong)puVar20 + 0x84) = uVar4;

      *(undefined4 *)(puVar20 + 0x11) = uVar5;

      *(undefined4 *)((longlong)puVar20 + 0x8c) = uVar6;

      *(undefined4 *)(puVar20 + 0x12) = uVar7;

      *(undefined4 *)((longlong)puVar20 + 0x94) = uVar8;

      *(undefined4 *)(puVar20 + 0x13) = uVar9;

      *(undefined4 *)((longlong)puVar20 + 0x9c) = uVar10;

      puVar20[0x14] = uVar2;

      *(undefined4 *)puVar17 = 0;

      iVar16 = FUN_1402f447c(iVar16,puVar17);

      if (iVar16 == -1) {

        puVar19 = (undefined4 *)FUN_1402e68b0();

        *puVar19 = 0x16;

        FUN_1402e9a80(puVar17);

        iVar16 = -1;

      }

      else {

        if (param_2 == '\0') {

          FUN_1402e8080();

        }

        piVar3 = *(int **)(local_res18 + 0x88);

        LOCK();

        iVar1 = *piVar3;

        *piVar3 = *piVar3 + -1;

        UNLOCK();

        if ((iVar1 == 1) && (*(undefined **)(local_res18 + 0x88) != &DAT_1403e91a0)) {

          FUN_1402e9a80();

        }

        *(undefined4 *)puVar17 = 1;

        *(undefined8 **)(local_res18 + 0x88) = puVar17;

        if ((DAT_1403e8ff0 & *(uint *)(local_res18 + 0x3a8)) == 0) {

          local_258 = &local_res18;

          local_250 = &local_res20;

          local_264 = 5;

          local_260[0] = 5;

          FUN_1402f3bf8(local_268,local_260,&local_258,&local_264);

          if (param_2 != '\0') {

            PTR_DAT_1403e8e90 = *local_res20;

          }

        }

        FUN_1402e9a80(0);

      }

    }

  }

  return iVar16;

}




