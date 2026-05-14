// Address: 0x1401ee270
// Ghidra name: FUN_1401ee270
// ============ 0x1401ee270 FUN_1401ee270 (size=1543) ============


void FUN_1401ee270(longlong param_1,int *param_2,longlong param_3)



{

  float fVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  int *piVar5;

  int *piVar6;

  char cVar7;

  int iVar8;

  code *pcVar9;

  undefined8 uVar10;

  ulonglong uVar11;

  undefined4 uVar12;

  int *piVar13;

  undefined8 uVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  int local_88;

  int local_84 [19];

  

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  cVar7 = FUN_1401ebd30();

  if (cVar7 == '\0') {

    return;

  }

  lVar3 = *(longlong *)(param_1 + 0x1f0);

  *(longlong *)(lVar2 + 0x220) = lVar3;

  if ((lVar3 == 0) &&

     ((FUN_14016ebe0(*(undefined8 *)(param_1 + 0x118),local_84,&local_88),

      local_84[0] != *(int *)(lVar2 + 0x228) || (local_88 != *(int *)(lVar2 + 0x22c))))) {

    *(undefined1 *)(lVar2 + 0x200) = 1;

    *(undefined1 *)(lVar2 + 0x252) = 1;

    *(int *)(lVar2 + 0x228) = local_84[0];

    *(int *)(lVar2 + 0x22c) = local_88;

  }

  while (param_2 != (int *)0x0) {

    iVar8 = *param_2;

    piVar13 = param_2;

    switch(iVar8) {

    case 1:

      iVar8 = memcmp((void *)(lVar2 + 0x204),param_2 + 4,0x10);

      if (iVar8 != 0) {

        uVar10 = *(undefined8 *)(param_2 + 6);

        *(undefined8 *)(lVar2 + 0x204) = *(undefined8 *)(param_2 + 4);

        *(undefined8 *)(lVar2 + 0x20c) = uVar10;

        *(undefined1 *)(lVar2 + 0x200) = 1;

        *(undefined1 *)(lVar2 + 0x252) = 1;

      }

      break;

    case 2:

      if (*(char *)(lVar2 + 0x251) != (char)param_2[2]) {

        *(char *)(lVar2 + 0x251) = (char)param_2[2];

        *(undefined1 *)(lVar2 + 0x250) = 1;

      }

      iVar8 = memcmp((void *)(lVar2 + 0x254),param_2 + 3,0x10);

      if (iVar8 != 0) {

        uVar10 = *(undefined8 *)(param_2 + 3);

        uVar14 = *(undefined8 *)(param_2 + 5);

        *(undefined1 *)(lVar2 + 0x252) = 1;

        *(undefined8 *)(lVar2 + 0x254) = uVar10;

        *(undefined8 *)(lVar2 + 0x25c) = uVar14;

      }

      break;

    case 3:

      fVar15 = (float)param_2[4];

      fVar1 = (float)param_2[8];

      fVar16 = fVar15 * (float)param_2[5];

      fVar17 = fVar15 * (float)param_2[6];

      fVar15 = fVar15 * (float)param_2[7];

      if ((((*(char *)(lVar2 + 0x269) != '\0') || (fVar16 != *(float *)(lVar2 + 0x26c))) ||

          (fVar17 != *(float *)(lVar2 + 0x270))) ||

         ((fVar15 != *(float *)(lVar2 + 0x274) || (fVar1 != *(float *)(lVar2 + 0x278))))) {

        (**(code **)(lVar2 + 0x70))(fVar16,fVar17,fVar15,fVar1);

        *(float *)(lVar2 + 0x26c) = fVar16;

        *(float *)(lVar2 + 0x270) = fVar17;

        *(float *)(lVar2 + 0x274) = fVar15;

        *(float *)(lVar2 + 0x278) = fVar1;

        *(undefined1 *)(lVar2 + 0x269) = 0;

      }

      break;

    case 4:

      fVar15 = (float)param_2[4];

      fVar1 = (float)param_2[8];

      fVar16 = fVar15 * (float)param_2[5];

      fVar17 = fVar15 * (float)param_2[6];

      fVar15 = fVar15 * (float)param_2[7];

      if ((((*(char *)(lVar2 + 0x27c) != '\0') || (fVar16 != *(float *)(lVar2 + 0x280))) ||

          (fVar17 != *(float *)(lVar2 + 0x284))) ||

         ((fVar15 != *(float *)(lVar2 + 0x288) || (fVar1 != *(float *)(lVar2 + 0x28c))))) {

        (**(code **)(lVar2 + 0x60))(fVar16,fVar17,fVar15,fVar1);

        *(float *)(lVar2 + 0x280) = fVar16;

        *(float *)(lVar2 + 0x284) = fVar17;

        *(float *)(lVar2 + 0x288) = fVar15;

        *(float *)(lVar2 + 0x28c) = fVar1;

        *(undefined1 *)(lVar2 + 0x27c) = 0;

      }

      if ((*(char *)(lVar2 + 0x251) != '\0') || (*(char *)(lVar2 + 0x250) != '\0')) {

        (**(code **)(lVar2 + 0x98))(0xc11);

        *(undefined1 *)(lVar2 + 0x250) = *(undefined1 *)(lVar2 + 0x251);

      }

      (**(code **)(lVar2 + 0x58))(0x4000);

      break;

    case 5:

    case 10:

      lVar3 = *(longlong *)(param_2 + 0xc);

      uVar11 = *(ulonglong *)(param_2 + 4);

      piVar6 = *(int **)(param_2 + 0x14);

      while (((((piVar5 = piVar6, piVar5 != (int *)0x0 && (*piVar5 == iVar8)) &&

               ((*(longlong *)(piVar5 + 0xc) == lVar3 &&

                ((piVar5[0xe] == param_2[0xe] && (piVar5[0xf] == param_2[0xf])))))) &&

              (piVar5[0x10] == param_2[0x10])) && (piVar5[0xb] == param_2[0xb]))) {

        uVar11 = uVar11 + *(longlong *)(piVar5 + 4);

        piVar13 = piVar5;

        piVar6 = *(int **)(piVar5 + 0x14);

      }

      if (lVar3 == 0) {

        cVar7 = FUN_1401ef800(lVar2,param_2,1,0);

      }

      else {

        cVar7 = FUN_1401ef4a0();

      }

      if (cVar7 != '\0') {

        lVar4 = *(longlong *)(param_2 + 2);

        uVar12 = 0;

        if (iVar8 != 5) {

          uVar12 = 4;

        }

        pcVar9 = *(code **)(lVar2 + 0x1a8);

        if (iVar8 != 5) {

          if (lVar3 == 0) {

            (*pcVar9)(2,0x1406,0x18);

            pcVar9 = *(code **)(lVar2 + 0x80);

            uVar10 = 4;

            uVar14 = 0x18;

          }

          else {

            (*pcVar9)(2,0x1406,0x20);

            (**(code **)(lVar2 + 0x80))(4,0x1406,0x20,lVar4 + param_3 + 8);

            pcVar9 = *(code **)(lVar2 + 0x170);

            uVar10 = 2;

            uVar14 = 0x20;

          }

          (*pcVar9)(uVar10,0x1406,uVar14);

          (**(code **)(lVar2 + 0xa8))(uVar12,0,uVar11 & 0xffffffff);

          (**(code **)(lVar2 + 0x70))

                    (*(undefined4 *)(lVar2 + 0x26c),*(undefined4 *)(lVar2 + 0x270),

                     *(undefined4 *)(lVar2 + 0x274),*(undefined4 *)(lVar2 + 0x278));

        }

        else {

          (*pcVar9)(2,0x1406,8);

          (**(code **)(lVar2 + 0xa8))(uVar12,0,uVar11 & 0xffffffff);

        }

      }

      break;

    case 6:

      cVar7 = FUN_1401ef800(lVar2,param_2,1,0);

      if (cVar7 != '\0') {

        uVar11 = *(ulonglong *)(param_2 + 4);

        (**(code **)(lVar2 + 0x1a8))(2,0x1406,8);

        if (uVar11 < 3) {

          piVar6 = *(int **)(param_2 + 0x14);

          while ((((piVar5 = piVar6, piVar5 != (int *)0x0 && (*piVar5 == 6)) &&

                  (*(longlong *)(piVar5 + 4) == 2)) && (piVar5[0xb] == param_2[0xb]))) {

            uVar11 = uVar11 + 2;

            piVar13 = piVar5;

            piVar6 = *(int **)(piVar5 + 0x14);

          }

          (**(code **)(lVar2 + 0xa8))(1,0,uVar11 & 0xffffffff);

        }

        else {

          (**(code **)(lVar2 + 0xa8))(3,0,uVar11 & 0xffffffff);

        }

      }

    }

    param_2 = *(int **)(piVar13 + 0x14);

  }

  if (*(char *)(lVar2 + 0x266) != '\0') {

    (**(code **)(lVar2 + 0xa0))(0x8074);

    *(undefined1 *)(lVar2 + 0x266) = 0;

  }

  if (*(char *)(lVar2 + 0x267) != '\0') {

    (**(code **)(lVar2 + 0xa0))(0x8076);

    *(undefined1 *)(lVar2 + 0x267) = 0;

  }

  if (*(char *)(lVar2 + 0x268) != '\0') {

    (**(code **)(lVar2 + 0xa0))(0x8078);

    *(undefined1 *)(lVar2 + 0x268) = 0;

  }

  FUN_1401ebd90(&DAT_14039bcb9,param_1,"SDL_render_gl.c",0x64f,"GL_RunCommandQueue");

  return;

}




