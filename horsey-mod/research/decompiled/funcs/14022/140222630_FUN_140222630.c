// Address: 0x140222630
// Ghidra name: FUN_140222630
// ============ 0x140222630 FUN_140222630 (size=581) ============


undefined8 FUN_140222630(undefined8 param_1,HDC param_2,longlong param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint uVar4;

  undefined4 extraout_var;

  undefined4 extraout_var_00;

  uint uVar6;

  int iVar7;

  int iPixelFormat;

  int local_res20;

  uint local_68;

  tagPIXELFORMATDESCRIPTOR local_60;

  ulonglong uVar5;

  

  iPixelFormat = 1;

  local_68 = 0xffffffff;

  iVar7 = 0;

  local_res20 = 0;

  iVar2 = DescribePixelFormat(param_2,1,0x28,(LPPIXELFORMATDESCRIPTOR)0x0);

  uVar5 = CONCAT44(extraout_var,iVar2);

  if (0 < iVar2) {

    do {

      iVar3 = DescribePixelFormat(param_2,iPixelFormat,0x28,&local_60);

      uVar5 = CONCAT44(extraout_var_00,iVar3);

      iVar1 = local_res20;

      uVar6 = local_68;

      if ((((iVar3 != 0) &&

           (uVar4 = *(uint *)(param_3 + 4) & local_60.dwFlags, uVar5 = (ulonglong)uVar4,

           uVar4 == *(uint *)(param_3 + 4))) &&

          (uVar5 = 0, local_60.iLayerType == *(BYTE *)(param_3 + 0x1a))) &&

         (uVar5 = 0, local_60.iPixelType == *(BYTE *)(param_3 + 8))) {

        uVar5 = 0;

        if (((*(byte *)(param_3 + 9) <= local_60.cColorBits) &&

            (*(byte *)(param_3 + 10) <= local_60.cRedBits)) &&

           (*(byte *)(param_3 + 0xc) <= local_60.cGreenBits)) {

          if (((*(byte *)(param_3 + 0xe) <= local_60.cBlueBits) &&

              (*(byte *)(param_3 + 0x10) <= local_60.cAlphaBits)) &&

             (((*(byte *)(param_3 + 0x12) <= local_60.cAccumBits &&

               ((((*(byte *)(param_3 + 0x13) <= local_60.cAccumRedBits &&

                  (*(byte *)(param_3 + 0x14) <= local_60.cAccumGreenBits)) &&

                 (*(byte *)(param_3 + 0x15) <= local_60.cAccumBlueBits)) &&

                ((*(byte *)(param_3 + 0x16) <= local_60.cAccumAlphaBits &&

                 (*(byte *)(param_3 + 0x17) <= local_60.cDepthBits)))))) &&

              (*(byte *)(param_3 + 0x18) <= local_60.cStencilBits)))) {

            uVar5 = 0;

            uVar6 = (uint)local_60.cColorBits +

                    (((((((((((((uint)local_60.cStencilBits - (uint)*(byte *)(param_3 + 9)) -

                              (uint)*(byte *)(param_3 + 10)) - (uint)*(byte *)(param_3 + 0xc)) -

                            (uint)*(byte *)(param_3 + 0xe)) - (uint)*(byte *)(param_3 + 0x10)) -

                          (uint)*(byte *)(param_3 + 0x12)) - (uint)*(byte *)(param_3 + 0x13)) -

                        (uint)*(byte *)(param_3 + 0x14)) - (uint)*(byte *)(param_3 + 0x15)) -

                      (uint)*(byte *)(param_3 + 0x16)) - (uint)*(byte *)(param_3 + 0x17)) -

                    (uint)*(byte *)(param_3 + 0x18)) + (uint)local_60.cDepthBits +

                    (uint)local_60.cAccumAlphaBits + (uint)local_60.cAccumBlueBits +

                    (uint)local_60.cAccumGreenBits + (uint)local_60.cAccumRedBits +

                    (uint)local_60.cAccumBits + (uint)local_60.cAlphaBits + (uint)local_60.cBlueBits

                    + (uint)local_60.cGreenBits + (uint)local_60.cRedBits;

            iVar7 = iPixelFormat;

            iVar1 = iPixelFormat;

            if (uVar6 < local_68) goto LAB_140222844;

          }

          uVar5 = 0;

          iVar7 = local_res20;

          iVar1 = local_res20;

          uVar6 = local_68;

        }

      }

LAB_140222844:

      local_68 = uVar6;

      local_res20 = iVar1;

      iPixelFormat = iPixelFormat + 1;

    } while (iPixelFormat <= iVar2);

  }

  return CONCAT71((int7)(uVar5 >> 8),iVar7 != 0);

}




