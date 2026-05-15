// Address: 0x1401f32b0
// Ghidra name: FUN_1401f32b0
// ============ 0x1401f32b0 FUN_1401f32b0 (size=1075) ============


void FUN_1401f32b0(longlong param_1,int *param_2,undefined8 param_3)



{

  float fVar1;

  longlong lVar2;

  undefined8 uVar3;

  int *piVar4;

  int *piVar5;

  char cVar6;

  int iVar7;

  float *pfVar8;

  undefined8 uVar9;

  int *piVar10;

  undefined4 uVar11;

  longlong lVar12;

  ulonglong uVar13;

  longlong lVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  int local_res8 [2];

  int local_78 [20];

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if ((*(int **)(param_1 + 0x1f0) == (int *)0x0) ||

     ((iVar7 = **(int **)(param_1 + 0x1f0), iVar7 != 0x16362004 && (iVar7 != 0x16161804)))) {

    lVar14 = 0;

  }

  else {

    lVar14 = 1;

  }

  cVar6 = FUN_1401f0320();

  if (cVar6 != '\0') {

    lVar12 = *(longlong *)(param_1 + 0x1f0);

    *(longlong *)(lVar2 + 0x280) = lVar12;

    if ((lVar12 == 0) &&

       ((FUN_14016ebe0(*(undefined8 *)(param_1 + 0x118),local_78,local_res8),

        local_78[0] != *(int *)(lVar2 + 0x2b8) || (local_res8[0] != *(int *)(lVar2 + 700))))) {

      *(undefined1 *)(lVar2 + 0x270) = 1;

      *(undefined1 *)(lVar2 + 0x28e) = 1;

      *(int *)(lVar2 + 0x2b8) = local_78[0];

      *(int *)(lVar2 + 700) = local_res8[0];

    }

    while (param_2 != (int *)0x0) {

      iVar7 = *param_2;

      piVar10 = param_2;

      switch(iVar7) {

      case 1:

        iVar7 = memcmp((void *)(lVar2 + 0x260),param_2 + 4,0x10);

        if (iVar7 != 0) {

          uVar9 = *(undefined8 *)(param_2 + 6);

          *(undefined8 *)(lVar2 + 0x260) = *(undefined8 *)(param_2 + 4);

          *(undefined8 *)(lVar2 + 0x268) = uVar9;

          *(undefined1 *)(lVar2 + 0x270) = 1;

          *(undefined1 *)(lVar2 + 0x28e) = 1;

        }

        break;

      case 2:

        if (*(char *)(lVar2 + 0x28d) != (char)param_2[2]) {

          *(char *)(lVar2 + 0x28d) = (char)param_2[2];

          *(undefined1 *)(lVar2 + 0x28c) = 1;

        }

        iVar7 = memcmp((void *)(lVar2 + 0x290),param_2 + 3,0x10);

        if (iVar7 != 0) {

          uVar9 = *(undefined8 *)(param_2 + 3);

          uVar3 = *(undefined8 *)(param_2 + 5);

          *(undefined1 *)(lVar2 + 0x28e) = 1;

          *(undefined8 *)(lVar2 + 0x290) = uVar9;

          *(undefined8 *)(lVar2 + 0x298) = uVar3;

        }

        break;

      case 4:

        fVar15 = (float)param_2[4];

        fVar17 = fVar15 * (float)param_2[6];

        fVar16 = fVar15 * (float)param_2[lVar14 * 2 + 5];

        pfVar8 = (float *)(param_2 + 5);

        if ((char)lVar14 == '\0') {

          pfVar8 = (float *)(param_2 + 7);

        }

        fVar15 = fVar15 * *pfVar8;

        fVar1 = (float)param_2[8];

        if ((((*(char *)(lVar2 + 0x2b4) != '\0') || (fVar16 != *(float *)(lVar2 + 0x2a4))) ||

            (fVar17 != *(float *)(lVar2 + 0x2a8))) ||

           ((fVar15 != *(float *)(lVar2 + 0x2ac) || (fVar1 != *(float *)(lVar2 + 0x2b0))))) {

          (**(code **)(lVar2 + 0x48))(fVar16,fVar17,fVar15,fVar1);

          *(float *)(lVar2 + 0x2a4) = fVar16;

          *(float *)(lVar2 + 0x2a8) = fVar17;

          *(float *)(lVar2 + 0x2ac) = fVar15;

          *(float *)(lVar2 + 0x2b0) = fVar1;

          *(undefined1 *)(lVar2 + 0x2b4) = 0;

        }

        if ((*(char *)(lVar2 + 0x28d) != '\0') || (*(char *)(lVar2 + 0x28c) != '\0')) {

          (**(code **)(lVar2 + 0x80))(0xc11);

          *(undefined1 *)(lVar2 + 0x28c) = *(undefined1 *)(lVar2 + 0x28d);

        }

        (**(code **)(lVar2 + 0x40))(0x4000);

        break;

      case 5:

      case 10:

        lVar12 = *(longlong *)(param_2 + 4);

        uVar11 = (undefined4)lVar12;

        piVar5 = *(int **)(param_2 + 0x14);

        while (((((piVar4 = piVar5, piVar4 != (int *)0x0 &&

                  (uVar11 = (undefined4)lVar12, *piVar4 == iVar7)) &&

                 ((*(longlong *)(piVar4 + 0xc) == *(longlong *)(param_2 + 0xc) &&

                  ((piVar4[0xe] == param_2[0xe] && (piVar4[0xf] == param_2[0xf])))))) &&

                (piVar4[0x10] == param_2[0x10])) && (piVar4[0xb] == param_2[0xb]))) {

          lVar12 = lVar12 + *(longlong *)(piVar4 + 4);

          uVar11 = (undefined4)lVar12;

          piVar10 = piVar4;

          piVar5 = *(int **)(piVar4 + 0x14);

        }

        if (*(longlong *)(param_2 + 0xc) == 0) {

          cVar6 = FUN_1401f4bb0(lVar2,param_2,1,param_3);

        }

        else {

          cVar6 = FUN_1401f4790(param_1,param_2,param_3);

        }

        if (cVar6 != '\0') {

          uVar9 = 0;

          if (iVar7 != 5) {

            uVar9 = 4;

          }

          (**(code **)(lVar2 + 0x90))(uVar9,0,uVar11);

        }

        break;

      case 6:

        cVar6 = FUN_1401f4bb0(lVar2,param_2,1,param_3);

        if (cVar6 != '\0') {

          uVar13 = *(ulonglong *)(param_2 + 4);

          if (uVar13 < 3) {

            piVar5 = *(int **)(param_2 + 0x14);

            while ((((piVar4 = piVar5, piVar4 != (int *)0x0 && (*piVar4 == 6)) &&

                    (*(longlong *)(piVar4 + 4) == 2)) && (piVar4[0xb] == param_2[0xb]))) {

              uVar13 = uVar13 + 2;

              piVar10 = piVar4;

              piVar5 = *(int **)(piVar4 + 0x14);

            }

            (**(code **)(lVar2 + 0x90))(1,0,uVar13);

          }

          else {

            (**(code **)(lVar2 + 0x90))(3,0);

          }

        }

      }

      param_2 = *(int **)(piVar10 + 0x14);

    }

    FUN_1401f4660(&DAT_14039bcb9,param_1,"SDL_render_gles2.c",0x676,"GLES2_RunCommandQueue");

    return;

  }

  return;

}




