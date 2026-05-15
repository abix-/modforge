// Address: 0x14020e6a0
// Ghidra name: FUN_14020e6a0
// ============ 0x14020e6a0 FUN_14020e6a0 (size=771) ============


undefined8 FUN_14020e6a0(uint param_1,ushort param_2,char *param_3)



{

  char cVar1;

  int iVar2;

  UINT UVar3;

  PRAWINPUTDEVICELIST pRawInputDeviceList;

  longlong lVar4;

  char *pcVar5;

  uint uVar6;

  uint uVar7;

  undefined4 local_res8 [2];

  uint local_res10 [2];

  uint local_res20 [2];

  uint local_268 [2];

  undefined4 local_260 [2];

  undefined2 local_258;

  undefined2 local_254;

  undefined1 local_240 [40];

  char local_218 [272];

  undefined1 local_108 [208];

  

  uVar7 = 0;

  param_1 = param_1 & 0xffff;

  local_res10[0] = 0;

  cVar1 = FUN_1402853c0();

  if ((cVar1 != '\0') || (cVar1 = FUN_14020a870(), cVar1 != '\0')) {

    cVar1 = FUN_1401597a0(param_1,param_2);

    if ((cVar1 != '\0') ||

       ((param_3 != (char *)0x0 && (iVar2 = strncmp(param_3,"Xbox ",5), iVar2 == 0)))) {

      return 1;

    }

    UVar3 = GetRawInputDeviceList((PRAWINPUTDEVICELIST)0x0,local_res10,0x10);

    if (((UVar3 != 0xffffffff) && (local_res10[0] != 0)) &&

       (pRawInputDeviceList = (PRAWINPUTDEVICELIST)FUN_1401841f0((ulonglong)local_res10[0] << 4),

       pRawInputDeviceList != (PRAWINPUTDEVICELIST)0x0)) {

      local_res10[0] = GetRawInputDeviceList(pRawInputDeviceList,local_res10,0x10);

      if ((local_res10[0] != 0xffffffff) && (uVar6 = local_res10[0], local_res10[0] != 0)) {

        do {

          FUN_1402f94c0(local_218,0,0x104);

          local_res20[0] = 0x20;

          local_268[0] = 0x104;

          local_260[0] = 0x20;

          if (((pRawInputDeviceList[uVar7].dwType == 2) &&

              ((UVar3 = GetRawInputDeviceInfoA

                                  (pRawInputDeviceList[uVar7].hDevice,0x2000000b,local_260,

                                   local_res20), uVar6 = local_res10[0], UVar3 != 0xffffffff &&

               (UVar3 = GetRawInputDeviceInfoA

                                  (pRawInputDeviceList[uVar7].hDevice,0x20000007,local_218,local_268

                                  ), uVar6 = local_res10[0], UVar3 != 0xffffffff)))) &&

             (lVar4 = thunk_FUN_1402c9340(local_218), uVar6 = local_res10[0], lVar4 != 0)) {

            if (CONCAT22(local_254,local_258) == ((uint)param_2 << 0x10 | param_1)) {

LAB_14020e97e:

              FUN_1401841e0(pRawInputDeviceList);

              return 1;

            }

            pcVar5 = (char *)thunk_FUN_1402c9340(local_218);

            uVar6 = local_res10[0];

            if ((pcVar5 == local_218) &&

               (lVar4 = thunk_FUN_1402c9340(local_218), uVar6 = local_res10[0], lVar4 != 0)) {

              if (local_218[0] != '\0') {

                pcVar5 = local_218;

                cVar1 = local_218[0];

                do {

                  if (cVar1 == '#') {

                    if (pcVar5[1] == '{') {

                      *pcVar5 = '\0';

                      break;

                    }

                    *pcVar5 = '\\';

                  }

                  cVar1 = pcVar5[1];

                  pcVar5 = pcVar5 + 1;

                } while (cVar1 != '\0');

              }

              iVar2 = CM_Locate_DevNodeA(local_res8,local_218 + 4,0);

              uVar6 = local_res10[0];

              if (iVar2 == 0) {

                FUN_14012ef10(local_240,0x20,"VID_%04X&PID_%04X",param_1,param_2);

                iVar2 = CM_Get_Parent(local_res8,local_res8[0],0);

                while (uVar6 = local_res10[0], iVar2 == 0) {

                  iVar2 = CM_Get_Device_IDA(local_res8[0],local_108,200,0);

                  if ((iVar2 == 0) && (lVar4 = thunk_FUN_1402c9340(local_108,local_240), lVar4 != 0)

                     ) goto LAB_14020e97e;

                  iVar2 = CM_Get_Parent(local_res8,local_res8[0],0);

                }

              }

            }

          }

          uVar7 = uVar7 + 1;

          if (uVar6 <= uVar7) {

            FUN_1401841e0(pRawInputDeviceList);

            return 0;

          }

        } while( true );

      }

      FUN_1401841e0(pRawInputDeviceList);

    }

  }

  return 0;

}




