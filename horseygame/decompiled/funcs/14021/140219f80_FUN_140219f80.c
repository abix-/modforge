// Address: 0x140219f80
// Ghidra name: FUN_140219f80
// ============ 0x140219f80 FUN_140219f80 (size=1294) ============


ulonglong FUN_140219f80(longlong param_1,char param_2)



{

  int iVar1;

  bool bVar2;

  char cVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  int iVar7;

  ulonglong uVar8;

  int *piVar9;

  uint uVar10;

  ulonglong *puVar11;

  int iVar12;

  longlong *plVar13;

  int local_res8 [2];

  char local_res10;

  uint local_res18 [2];

  int local_res20;

  int local_558;

  int local_554;

  int local_550;

  int local_548 [6];

  int local_530 [58];

  ulonglong local_448 [129];

  

  local_res18[0] = 0;

  local_554 = -1;

  local_550 = -1;

  local_res20 = -1;

  local_548[1] = *(undefined4 *)(param_1 + 0x3a0);

  local_548[3] = *(undefined4 *)(param_1 + 0x3a4);

  local_548[5] = *(undefined4 *)(param_1 + 0x3a8);

  local_res10 = '\0';

  local_548[0] = 0x3024;

  local_548[2] = 0x3023;

  local_548[4] = 0x3022;

  if (param_2 != '\0') {

    local_530[0] = 0x3027;

    local_530[1] = 0x3038;

  }

  iVar7 = *(int *)(param_1 + 0x3ac);

  uVar8 = 8;

  if (param_2 == '\0') {

    uVar8 = 6;

  }

  if (iVar7 != 0) {

    local_548[uVar8] = 0x3021;

    local_548[(int)uVar8 + 1] = iVar7;

    uVar8 = (ulonglong)((int)uVar8 + 2);

  }

  iVar7 = *(int *)(param_1 + 0x3b4);

  if (iVar7 != 0) {

    local_548[uVar8] = 0x3020;

    local_548[(int)uVar8 + 1] = iVar7;

    uVar8 = (ulonglong)((int)uVar8 + 2);

  }

  iVar7 = *(int *)(param_1 + 0x3b0);

  if (iVar7 != 0) {

    local_548[uVar8] = 0x3025;

    local_548[(int)uVar8 + 1] = iVar7;

    uVar8 = (ulonglong)((int)uVar8 + 2);

  }

  iVar7 = *(int *)(param_1 + 0x3b8);

  if (iVar7 != 0) {

    local_548[uVar8] = 0x3026;

    local_548[(int)uVar8 + 1] = iVar7;

    uVar8 = (ulonglong)((int)uVar8 + 2);

  }

  iVar7 = *(int *)(param_1 + 0x3d4);

  if (iVar7 != 0) {

    local_548[uVar8] = 0x3032;

    local_548[(int)uVar8 + 1] = iVar7;

    uVar8 = (ulonglong)((int)uVar8 + 2);

  }

  iVar7 = *(int *)(param_1 + 0x3d8);

  if (iVar7 != 0) {

    iVar12 = (int)uVar8;

    local_548[uVar8] = 0x3031;

    uVar8 = (ulonglong)(iVar12 + 2);

    local_548[(longlong)iVar12 + 1] = iVar7;

  }

  iVar7 = (int)uVar8;

  if (*(int *)(param_1 + 0x3dc) != 0) {

    local_548[iVar7] = 0x3339;

    lVar4 = (longlong)iVar7;

    iVar7 = iVar7 + 2;

    local_548[lVar4 + 1] = 0x333b;

  }

  lVar4 = *(longlong *)(param_1 + 0x690);

  if (*(char *)(lVar4 + 0x34) != '\0') {

    local_548[iVar7] = 0x3033;

    lVar5 = (longlong)iVar7;

    iVar7 = iVar7 + 2;

    local_548[lVar5 + 1] = 1;

  }

  iVar12 = *(int *)(param_1 + 0x3f0);

  local_548[iVar7] = 0x3040;

  if (iVar12 == 4) {

    if ((*(int *)(param_1 + 0x3e4) < 3) ||

       (cVar3 = FUN_1402191b0(param_1,0,"EGL_KHR_create_context"), cVar3 == '\0')) {

      if (*(int *)(param_1 + 0x3e4) < 2) {

        local_548[(longlong)iVar7 + 1] = 1;

      }

      else {

        local_548[(longlong)iVar7 + 1] = 4;

      }

    }

    else {

      local_548[(longlong)iVar7 + 1] = 0x40;

    }

    (**(code **)(*(longlong *)(param_1 + 0x690) + 200))(0x30a0);

  }

  else {

    local_548[(longlong)iVar7 + 1] = 8;

    (**(code **)(lVar4 + 200))(0x30a2);

  }

  plVar13 = (longlong *)(param_1 + 0x690);

  lVar4 = *plVar13;

  iVar12 = iVar7 + 2;

  if (*(int *)(lVar4 + 0x24) != 0) {

    lVar5 = (longlong)iVar12;

    lVar6 = (longlong)iVar12;

    iVar12 = iVar7 + 4;

    local_548[lVar5] = 0x3033;

    local_548[lVar6 + 1] = *(int *)(lVar4 + 0x24);

  }

  local_548[iVar12] = 0x3038;

  uVar8 = (**(code **)(lVar4 + 0x60))

                    (*(undefined8 *)(lVar4 + 0x10),local_548,local_448,0x80,local_res18);

  if (((int)uVar8 == 0) || (uVar8 = (ulonglong)local_res18[0], local_res18[0] == 0)) {

    return uVar8 & 0xffffffffffffff00;

  }

  lVar4 = *plVar13;

  if ((*(int *)(lVar4 + 0x30) != 0) && (iVar7 = 0, 0 < (int)local_res18[0])) {

    puVar11 = local_448;

    do {

      (**(code **)(lVar4 + 0xb0))(*(undefined8 *)(lVar4 + 0x10),*puVar11,0x302e,&local_558);

      lVar4 = *plVar13;

      if (*(int *)(lVar4 + 0x30) == local_558) {

        cVar3 = '\x01';

        local_res10 = '\x01';

        goto LAB_14021a26d;

      }

      iVar7 = iVar7 + 1;

      puVar11 = puVar11 + 1;

    } while (iVar7 < (int)local_res18[0]);

  }

  cVar3 = '\0';

LAB_14021a26d:

  iVar12 = 0;

  iVar7 = -1;

  if (0 < (int)local_res18[0]) {

    puVar11 = local_448;

    do {

      iVar7 = 0;

      if (((cVar3 == '\0') || (lVar4 = *(longlong *)(param_1 + 0x690), *(int *)(lVar4 + 0x30) == 0))

         || ((**(code **)(lVar4 + 0xb0))(*(undefined8 *)(lVar4 + 0x10),*puVar11,0x302e,&local_558),

            *(int *)(*(longlong *)(param_1 + 0x690) + 0x30) == local_558)) {

        (**(code **)(*(longlong *)(param_1 + 0x690) + 0xb0))

                  (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),*puVar11,0x3024,local_res8

                  );

        bVar2 = false;

        if ((local_res8[0] == 8) &&

           ((**(code **)(*(longlong *)(param_1 + 0x690) + 0xb0))

                      (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),*puVar11,0x3023,

                       local_res8), local_res8[0] == 8)) {

          (**(code **)(*(longlong *)(param_1 + 0x690) + 0xb0))

                    (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),*puVar11,0x3022,

                     local_res8);

          bVar2 = false;

          if (local_res8[0] == 8) {

            bVar2 = true;

          }

        }

        uVar10 = 0;

        piVar9 = local_548 + 1;

        do {

          iVar1 = piVar9[-1];

          if (iVar1 == 0x3038) break;

          if ((*piVar9 != -1) && (iVar1 - 0x3021U < 6)) {

            (**(code **)(*(longlong *)(param_1 + 0x690) + 0xb0))

                      (*(undefined8 *)(*(longlong *)(param_1 + 0x690) + 0x10),*puVar11,iVar1,

                       local_res8);

            iVar7 = iVar7 + (local_res8[0] - *piVar9);

          }

          uVar10 = uVar10 + 2;

          piVar9 = piVar9 + 2;

        } while (uVar10 < 0x3f);

        if ((iVar7 < local_554) || (local_554 == -1)) {

          *(ulonglong *)(*(longlong *)(param_1 + 0x690) + 0x18) = *puVar11;

          local_554 = iVar7;

        }

        if ((!bVar2) || ((iVar1 = iVar12, local_550 <= iVar7 && (local_550 != -1))))

        goto LAB_14021a408;

      }

      else {

LAB_14021a408:

        iVar1 = local_res20;

        iVar7 = local_550;

      }

      local_550 = iVar7;

      local_res20 = iVar1;

      iVar12 = iVar12 + 1;

      puVar11 = puVar11 + 1;

      iVar7 = local_res20;

      cVar3 = local_res10;

    } while (iVar12 < (int)local_res18[0]);

  }

  uVar10 = *(int *)(param_1 + 0x3a8) + *(int *)(param_1 + 0x3a4) + *(int *)(param_1 + 0x3a0);

  uVar8 = (ulonglong)uVar10;

  if (((int)uVar10 < 0x11) && (iVar7 != -1)) {

    uVar8 = local_448[iVar7];

    *(ulonglong *)(*(longlong *)(param_1 + 0x690) + 0x18) = uVar8;

  }

  return CONCAT71((int7)(uVar8 >> 8),1);

}




