// Address: 0x14018bef0
// Ghidra name: FUN_14018bef0
// ============ 0x14018bef0 FUN_14018bef0 (size=1186) ============


void FUN_14018bef0(undefined1 param_1)



{

  undefined4 *puVar1;

  DWORD DVar2;

  undefined4 uVar3;

  HDEVINFO pvVar4;

  char cVar5;

  int iVar6;

  UINT UVar7;

  undefined8 *puVar8;

  PRAWINPUTDEVICELIST pRawInputDeviceList;

  longlong lVar9;

  undefined8 uVar10;

  char *pcVar11;

  char *pcVar12;

  ulonglong uVar13;

  ulonglong uVar14;

  PRAWINPUTDEVICELIST ptVar15;

  ulonglong uVar16;

  uint uVar17;

  ulonglong uVar18;

  ulonglong uVar19;

  uint local_res10 [2];

  undefined4 local_res18 [2];

  undefined4 local_res20 [2];

  int local_1c8;

  int local_1c4;

  PRAWINPUTDEVICELIST local_1c0;

  uint local_1b8;

  uint local_1b4 [3];

  longlong local_1a8;

  longlong local_1a0;

  ulonglong local_198;

  ulonglong local_190;

  HDEVINFO local_188;

  undefined4 local_180 [7];

  undefined4 local_164;

  char local_158 [280];

  

  puVar8 = (undefined8 *)FUN_14016dcf0();

  uVar14 = 0;

  local_res10[0] = 0;

  local_1c8 = 0;

  local_1b8 = 0;

  local_198 = 0;

  local_1c4 = 0;

  local_1b4[0] = 0;

  local_190 = 0;

  if (((((puVar8 != (undefined8 *)0x0) && (iVar6 = strcmp((char *)*puVar8,"windows"), iVar6 == 0))

       && (*(char *)(puVar8[0xd0] + 0xf9) != '\0')) &&

      ((*(longlong *)(puVar8[0xd0] + 0x138) == 0 &&

       (UVar7 = GetRawInputDeviceList((PRAWINPUTDEVICELIST)0x0,local_res10,0x10),

       UVar7 != 0xffffffff)))) &&

     ((local_res10[0] != 0 &&

      (pRawInputDeviceList = (PRAWINPUTDEVICELIST)FUN_1401841f0((ulonglong)local_res10[0] << 4),

      pRawInputDeviceList != (PRAWINPUTDEVICELIST)0x0)))) {

    local_1c0 = pRawInputDeviceList;

    local_res10[0] = GetRawInputDeviceList(pRawInputDeviceList,local_res10,0x10);

    if (local_res10[0] == 0xffffffff) {

      FUN_1401841e0(pRawInputDeviceList);

      return;

    }

    local_188 = SetupDiGetClassDevsA((GUID *)0x0,(PCSTR)0x0,(HWND)0x0,6);

    lVar9 = FUN_140183350(&local_1c8);

    local_1a8 = lVar9;

    local_1a0 = FUN_1401610b0(&local_1c4);

    pvVar4 = local_188;

    uVar16 = uVar14;

    uVar18 = uVar14;

    uVar19 = uVar14;

    if (local_res10[0] != 0) {

      do {

        FUN_1402f94c0(local_158,0,0x104);

        ptVar15 = pRawInputDeviceList + uVar14;

        local_1b4[1] = 0x20;

        local_1b4[2] = 0x104;

        local_res20[0] = 0;

        local_res18[0] = 0;

        DVar2 = ptVar15->dwType;

        if ((DVar2 == 1) || (DVar2 == 0)) {

          local_180[0] = 0x20;

          UVar7 = GetRawInputDeviceInfoA(ptVar15->hDevice,0x2000000b,local_180,local_1b4 + 1);

          if ((UVar7 != 0xffffffff) &&

             (UVar7 = GetRawInputDeviceInfoA(ptVar15->hDevice,0x20000007,local_158,local_1b4 + 2),

             UVar7 != 0xffffffff)) {

            for (pcVar12 = local_158;

                (cVar5 = *pcVar12, cVar5 == '\\' || (pcVar11 = pcVar12, cVar5 == '?'));

                pcVar12 = pcVar12 + 1) {

            }

            while (cVar5 != '\0') {

              if (cVar5 == '#') {

                *pcVar11 = '\\';

              }

              else if (cVar5 == '{') {

                if ((pcVar12 < pcVar11) && (pcVar11[-1] == '\\')) {

                  pcVar11 = pcVar11 + -1;

                }

                break;

              }

              cVar5 = pcVar11[1];

              pcVar11 = pcVar11 + 1;

            }

            *pcVar11 = '\0';

            FUN_14012ef30(pcVar12,"HID\\VID_%X&PID_%X&",local_res20,local_res18);

            if (DVar2 == 0) {

              cVar5 = FUN_140018e60((undefined2)local_res20[0]);

              pRawInputDeviceList = local_1c0;

              if (cVar5 != '\0') {

                uVar3 = *(undefined4 *)&ptVar15->hDevice;

                FUN_14018b5a0(uVar3,&local_190,local_1b4);

                cVar5 = FUN_14018b9e0(uVar3,local_1a0,local_1c4);

                pRawInputDeviceList = local_1c0;

                if (cVar5 == '\0') {

                  uVar10 = FUN_14018b6b0(ptVar15->hDevice,pvVar4,pcVar12,(undefined2)local_res20[0],

                                         (undefined2)local_res18[0],"Mouse",param_1);

                  FUN_140160670(uVar3);

LAB_14018c288:

                  FUN_1401841e0(uVar10);

                  pRawInputDeviceList = local_1c0;

                }

              }

            }

            else {

              pRawInputDeviceList = local_1c0;

              if (DVar2 == 1) {

                cVar5 = FUN_1401834e0((undefined2)local_res20[0],(undefined2)local_res18[0],

                                      local_164);

                pRawInputDeviceList = local_1c0;

                if (cVar5 != '\0') {

                  uVar3 = *(undefined4 *)&ptVar15->hDevice;

                  FUN_14018b5a0(uVar3,&local_198,&local_1b8);

                  cVar5 = FUN_14018b9e0(uVar3,local_1a8,local_1c8);

                  pRawInputDeviceList = local_1c0;

                  if (cVar5 == '\0') {

                    uVar10 = FUN_14018b6b0(ptVar15->hDevice,pvVar4,pcVar12,

                                           (undefined2)local_res20[0],(undefined2)local_res18[0],

                                           "Keyboard",param_1);

                    FUN_140182e30(uVar3);

                    goto LAB_14018c288;

                  }

                }

              }

            }

          }

        }

        uVar17 = (int)uVar14 + 1;

        uVar14 = (ulonglong)uVar17;

      } while (uVar17 < local_res10[0]);

      uVar14 = (ulonglong)local_1b8;

      uVar19 = (ulonglong)local_1b4[0];

      uVar16 = local_190;

      lVar9 = local_1a8;

      uVar18 = local_198;

    }

    uVar13 = (ulonglong)local_1c8;

    if (local_1c8 != 0) {

      lVar9 = lVar9 + uVar13 * 4;

      do {

        puVar1 = (undefined4 *)(lVar9 + -4);

        lVar9 = lVar9 + -4;

        uVar17 = (int)uVar13 - 1;

        uVar13 = (ulonglong)uVar17;

        cVar5 = FUN_14018b9e0(*puVar1,uVar18,uVar14);

        if (cVar5 == '\0') {

          FUN_140183700();

        }

      } while (uVar17 != 0);

    }

    uVar14 = (ulonglong)local_1c4;

    if (local_1c4 != 0) {

      lVar9 = local_1a0 + uVar14 * 4;

      do {

        puVar1 = (undefined4 *)(lVar9 + -4);

        lVar9 = lVar9 + -4;

        uVar17 = (int)uVar14 - 1;

        uVar14 = (ulonglong)uVar17;

        cVar5 = FUN_14018b9e0(*puVar1,uVar16,uVar19);

        if (cVar5 == '\0') {

          FUN_140162780();

        }

      } while (uVar17 != 0);

    }

    FUN_1401841e0(local_1a8);

    FUN_1401841e0(uVar18);

    FUN_1401841e0(local_1a0);

    FUN_1401841e0(uVar16);

    SetupDiDestroyDeviceInfoList(local_188);

    FUN_1401841e0(local_1c0);

  }

  return;

}




