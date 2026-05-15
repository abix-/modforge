// Address: 0x1402f6118
// Ghidra name: FUN_1402f6118
// ============ 0x1402f6118 FUN_1402f6118 (size=1043) ============


int FUN_1402f6118(undefined4 *param_1,uint *param_2,LPCWSTR param_3,uint param_4,undefined4 param_5,

                 undefined4 param_6)



{

  byte *pbVar1;

  uint uVar2;

  uint uVar3;

  DWORD DVar4;

  int iVar5;

  ulonglong *puVar6;

  undefined4 *puVar7;

  int *piVar8;

  HANDLE pvVar9;

  ulonglong uVar10;

  byte bVar11;

  undefined1 local_c8 [4];

  DWORD local_c4;

  undefined8 local_c0;

  ulonglong uStack_b8;

  ulonglong local_b0;

  byte local_a8;

  _SECURITY_ATTRIBUTES local_a0;

  ulonglong local_88;

  ulonglong local_80;

  ulonglong local_78;

  ulonglong local_68;

  ulonglong uStack_60;

  ulonglong local_58;

  undefined1 local_48 [32];

  

  puVar6 = (ulonglong *)FUN_1402f5cf0(local_48,param_4,param_5,param_6);

  local_c0 = *puVar6;

  uStack_b8 = puVar6[1];

  local_b0 = puVar6[2];

  local_78 = puVar6[1] >> 0x20;

  DVar4 = (DWORD)(puVar6[1] >> 0x20);

  local_88 = local_b0;

  local_68 = local_c0;

  uStack_60 = uStack_b8;

  if (DVar4 == 0xffffffff) {

    puVar7 = (undefined4 *)FUN_1402e688c();

    *puVar7 = 0;

    *param_2 = 0xffffffff;

    goto LAB_1402f6197;

  }

  uVar3 = _alloc_osfhnd();

  *param_2 = uVar3;

  if (uVar3 == 0xffffffff) {

    puVar7 = (undefined4 *)FUN_1402e688c();

    *puVar7 = 0;

    *param_2 = 0xffffffff;

    puVar7 = (undefined4 *)FUN_1402e68b0();

    *puVar7 = 0x18;

    goto LAB_1402f6197;

  }

  local_c4 = (DWORD)uStack_60;

  *param_1 = 1;

  uVar3 = (uint)(local_b0 >> 0x20) | (uint)local_b0;

  local_80 = (ulonglong)uVar3;

  local_a0.bInheritHandle = ~(param_4 >> 7) & 1;

  local_a0.nLength = 0x18;

  local_a0._4_4_ = 0;

  local_a0._20_4_ = 0;

  local_a0.lpSecurityDescriptor = (LPVOID)0x0;

  pvVar9 = CreateFileW(param_3,(DWORD)(local_68 >> 0x20),DVar4,&local_a0,local_c4,uVar3,(HANDLE)0x0)

  ;

  if (pvVar9 == (HANDLE)0xffffffffffffffff) {

    uVar2 = (uint)(local_68 >> 0x20);

    if (((uVar2 & 0xc0000000) == 0xc0000000) && ((param_4 & 1) != 0)) {

      local_c0 = CONCAT44(uVar2,(undefined4)local_c0) & 0x7fffffffffffffff;

      pvVar9 = CreateFileW(param_3,(DWORD)(local_c0 >> 0x20),DVar4,&local_a0,local_c4,uVar3,

                           (HANDLE)0x0);

      uVar3 = uVar2 & 0x7fffffff;

      if (pvVar9 != (HANDLE)0xffffffffffffffff) goto LAB_1402f62d1;

    }

    pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x38 +

                     (ulonglong)(*param_2 & 0x3f) * 0x48);

    *pbVar1 = *pbVar1 & 0xfe;

    DVar4 = GetLastError();

    FUN_1402e6840(DVar4);

  }

  else {

    uVar3 = local_c0._4_4_;

LAB_1402f62d1:

    DVar4 = GetFileType(pvVar9);

    if (DVar4 != 0) {

      if (DVar4 == 2) {

        bVar11 = (byte)local_c0 | 0x40;

      }

      else {

        bVar11 = (byte)local_c0;

        if (DVar4 == 3) {

          bVar11 = (byte)local_c0 | 8;

        }

      }

      FUN_1402f4cac(*param_2,pvVar9);

      local_a8 = bVar11 | 1;

      local_c0 = CONCAT71(local_c0._1_7_,bVar11) | 1;

      *(byte *)((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x38 +

               (ulonglong)(*param_2 & 0x3f) * 0x48) = local_a8;

      *(undefined1 *)

       ((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x39 + (ulonglong)(*param_2 & 0x3f) * 0x48)

           = 0;

      if (((param_4 & 2) == 0) || (iVar5 = truncate_ctrl_z_if_present(*param_2), iVar5 == 0)) {

        local_68 = local_c0;

        uStack_60 = uStack_b8;

        local_c8[0] = 0;

        local_58 = local_88;

        iVar5 = FUN_1402f5a70(*param_2,&local_68,param_4,local_c8);

        uVar2 = *param_2;

        if (iVar5 == 0) {

          *(undefined1 *)

           ((&DAT_1403ff160)[(longlong)(int)uVar2 >> 6] + 0x39 + (ulonglong)(uVar2 & 0x3f) * 0x48) =

               local_c8[0];

          uVar10 = (ulonglong)(*param_2 & 0x3f);

          pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x3d + uVar10 * 0x48);

          *pbVar1 = *pbVar1 ^ ((byte)(param_4 >> 0x10) ^

                              *(byte *)((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x3d +

                                       uVar10 * 0x48)) & 1;

          if (((local_a8 & 0x48) == 0) && ((param_4 & 8) != 0)) {

            pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x38 +

                             (ulonglong)(*param_2 & 0x3f) * 0x48);

            *pbVar1 = *pbVar1 | 0x20;

          }

          if (((uVar3 & 0xc0000000) == 0xc0000000) && ((param_4 & 1) != 0)) {

            CloseHandle(pvVar9);

            local_c0 = CONCAT44(uVar3,(undefined4)local_c0) & 0x7fffffffffffffff;

            pvVar9 = CreateFileW(param_3,(DWORD)(local_c0 >> 0x20),(DWORD)local_78,&local_a0,

                                 local_c4,(DWORD)local_80,(HANDLE)0x0);

            if (pvVar9 == (HANDLE)0xffffffffffffffff) {

              DVar4 = GetLastError();

              FUN_1402e6840(DVar4);

              pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x38 +

                               (ulonglong)(*param_2 & 0x3f) * 0x48);

              *pbVar1 = *pbVar1 & 0xfe;

              FUN_1402f4ed4(*param_2);

              goto LAB_1402f6197;

            }

            *(HANDLE *)

             ((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x28 +

             (ulonglong)(*param_2 & 0x3f) * 0x48) = pvVar9;

          }

          return 0;

        }

      }

      else {

        uVar2 = *param_2;

      }

      FUN_1402e9c3c(uVar2);

      return iVar5;

    }

    DVar4 = GetLastError();

    FUN_1402e6840(DVar4);

    pbVar1 = (byte *)((&DAT_1403ff160)[(longlong)(int)*param_2 >> 6] + 0x38 +

                     (ulonglong)(*param_2 & 0x3f) * 0x48);

    *pbVar1 = *pbVar1 & 0xfe;

    CloseHandle(pvVar9);

    if (DVar4 == 0) {

      puVar7 = (undefined4 *)FUN_1402e68b0();

      *puVar7 = 0xd;

    }

  }

LAB_1402f6197:

  piVar8 = (int *)FUN_1402e68b0();

  return *piVar8;

}




