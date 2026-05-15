// Address: 0x140209a70
// Ghidra name: FUN_140209a70
// ============ 0x140209a70 FUN_140209a70 (size=978) ============


void FUN_140209a70(HANDLE param_1)



{

  longlong *plVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  char cVar4;

  undefined1 uVar5;

  UINT UVar6;

  undefined4 uVar7;

  longlong lVar8;

  LPVOID pData;

  HANDLE pvVar9;

  longlong lVar10;

  undefined8 uVar11;

  undefined8 uVar12;

  undefined8 uVar13;

  undefined4 *puVar14;

  longlong lVar15;

  uint local_res10 [2];

  undefined8 local_258;

  undefined8 uStack_250;

  ulonglong local_248;

  undefined8 uStack_240;

  undefined1 local_238 [16];

  undefined2 local_228 [128];

  CHAR local_128 [272];

  

  FUN_1402f94c0(local_128,0,0x104);

  pvVar9 = param_1;

  lVar8 = FUN_140209f60();

  if (lVar8 == 0) {

    local_res10[0] = 0x20;

    local_258 = 0;

    uStack_250 = 0;

    local_248 = 0;

    uStack_240 = 0;

    UVar6 = GetRawInputDeviceInfoA(pvVar9,0x2000000b,&local_258,local_res10);

    if ((UVar6 != 0xffffffff) && (local_258._4_4_ == 2)) {

      local_res10[0] = 0x104;

      UVar6 = GetRawInputDeviceInfoA(param_1,0x20000007,local_128,local_res10);

      if ((UVar6 != 0xffffffff) &&

         (lVar8 = thunk_FUN_1402c9340(local_128,&DAT_140350290), lVar8 != 0)) {

        cVar4 = FUN_14015ba80(uStack_250 & 0xffff,uStack_250._4_2_,local_248 & 0xffff,&DAT_14039bcb9

                             );

        if (cVar4 == '\0') {

          cVar4 = FUN_1401599b0(&PTR_FUN_1403e4e20,uStack_250 & 0xffff,uStack_250._4_2_,

                                local_248 & 0xffff,&DAT_14039bcb9);

          if ((cVar4 == '\0') && (lVar8 = FUN_1401841a0(1,0x60), lVar8 != 0)) {

            *(HANDLE *)(lVar8 + 0x40) = param_1;

            *(short *)(lVar8 + 0x18) = (short)uStack_250;

            *(short *)(lVar8 + 0x1a) = (short)(uStack_250 >> 0x20);

            *(undefined2 *)(lVar8 + 0x1c) = (undefined2)local_248;

            *(undefined1 *)(lVar8 + 0x2e) = 1;

            uVar5 = FUN_1401597a0();

            *(undefined1 *)(lVar8 + 0x2f) = uVar5;

            uVar7 = FUN_140209a00(*(undefined2 *)(lVar8 + 0x18),*(undefined2 *)(lVar8 + 0x1a));

            *(undefined4 *)(lVar8 + 0x30) = uVar7;

            uVar12 = 0;

            local_res10[0] = 0;

            UVar6 = GetRawInputDeviceInfoA(param_1,0x20000005,(LPVOID)0x0,local_res10);

            if (UVar6 != 0xffffffff) {

              pData = (LPVOID)FUN_1401841a0(local_res10[0],1);

              *(LPVOID *)(lVar8 + 0x38) = pData;

              if (((pData != (LPVOID)0x0) &&

                  (UVar6 = GetRawInputDeviceInfoA(param_1,0x20000005,pData,local_res10),

                  UVar6 != 0xffffffff)) &&

                 (pvVar9 = CreateFileA(local_128,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,

                                       (HANDLE)0x0), pvVar9 != (HANDLE)0xffffffffffffffff)) {

                local_228[0] = 0;

                cVar4 = (*DAT_1403ffc38)(pvVar9,local_228,0x100);

                uVar11 = uVar12;

                if (cVar4 != '\0') {

                  lVar10 = FUN_14012fd40(local_228);

                  uVar11 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_228,lVar10 * 2 + 2);

                }

                local_228[0] = 0;

                cVar4 = (*DAT_1403ffc30)(pvVar9,local_228,0x100);

                if (cVar4 != '\0') {

                  lVar10 = FUN_14012fd40(local_228);

                  uVar12 = FUN_140197820(&DAT_14039c6f0,"UTF-16LE",local_228,lVar10 * 2 + 2);

                }

                uVar13 = FUN_1401578c0(*(undefined2 *)(lVar8 + 0x18),*(undefined2 *)(lVar8 + 0x1a),

                                       uVar11,uVar12);

                *(undefined8 *)(lVar8 + 8) = uVar13;

                puVar14 = (undefined4 *)

                          FUN_140157780(local_238,3,*(undefined2 *)(lVar8 + 0x18),

                                        *(undefined2 *)(lVar8 + 0x1a),*(undefined2 *)(lVar8 + 0x1c),

                                        uVar11,uVar12,0x72,0);

                uVar7 = puVar14[1];

                uVar2 = puVar14[2];

                uVar3 = puVar14[3];

                *(undefined4 *)(lVar8 + 0x1e) = *puVar14;

                *(undefined4 *)(lVar8 + 0x22) = uVar7;

                *(undefined4 *)(lVar8 + 0x26) = uVar2;

                *(undefined4 *)(lVar8 + 0x2a) = uVar3;

                FUN_1401841e0(uVar11);

                FUN_1401841e0(uVar12);

                uVar12 = FUN_14012f0d0(local_128);

                *(undefined8 *)(lVar8 + 0x10) = uVar12;

                CloseHandle(pvVar9);

                uVar7 = FUN_1401aa810();

                *(undefined4 *)(lVar8 + 0x50) = uVar7;

                FUN_140209a50(lVar8);

                lVar10 = DAT_1403ffc50;

                if (DAT_1403ffc50 != 0) {

                  do {

                    lVar15 = lVar10;

                    plVar1 = (longlong *)(lVar15 + 0x58);

                    lVar10 = *plVar1;

                  } while (lVar10 != 0);

                  if (lVar15 != 0) {

                    DAT_1403fd1b4 = DAT_1403fd1b4 + 1;

                    *plVar1 = lVar8;

                    FUN_14015a2b0(*(undefined4 *)(lVar8 + 0x50));

                    return;

                  }

                }

                DAT_1403fd1b4 = DAT_1403fd1b4 + 1;

                DAT_1403ffc50 = lVar8;

                FUN_14015a2b0(*(undefined4 *)(lVar8 + 0x50));

                return;

              }

            }

            FUN_1401841e0(*(undefined8 *)(lVar8 + 8));

            FUN_1401841e0(*(undefined8 *)(lVar8 + 0x10));

            FUN_1401841e0(lVar8);

          }

        }

      }

    }

  }

  return;

}




