// Address: 0x14021f4b0
// Ghidra name: FUN_14021f4b0
// ============ 0x14021f4b0 FUN_14021f4b0 (size=499) ============


longlong FUN_14021f4b0(undefined2 param_1,undefined2 param_2,undefined8 param_3)



{

  char cVar1;

  int iVar2;

  longlong lVar3;

  HDC hdc;

  undefined2 local_res8 [4];

  undefined4 local_198;

  undefined8 local_194;

  undefined8 local_18c;

  undefined2 local_184;

  undefined2 local_182;

  undefined2 local_180 [4];

  undefined4 local_178 [70];

  int local_60;

  undefined2 local_50;

  undefined1 local_4c;

  undefined1 local_49;

  undefined1 local_44 [44];

  

  local_194 = 0;

  local_184 = 0;

  local_18c = 0xc00848;

  local_198 = 0xffff0001;

  local_182 = param_1;

  local_180[0] = param_2;

  FUN_14021fa90(&local_182,local_180);

  lVar3 = FUN_1401841a0(1,0x28);

  if (lVar3 != 0) {

    cVar1 = FUN_14021f290(lVar3,&local_198,0x1a);

    if (cVar1 != '\0') {

      local_res8[0] = 0;

      cVar1 = FUN_14021f290(lVar3,local_res8,2);

      if (((cVar1 != '\0') && (cVar1 = FUN_14021f290(lVar3,local_res8,2), cVar1 != '\0')) &&

         (cVar1 = FUN_14021f3b0(lVar3,param_3), cVar1 != '\0')) {

        local_178[0] = 0x158;

        SystemParametersInfoA(0x29,0,local_178,0);

        hdc = GetDC((HWND)0x0);

        iVar2 = GetDeviceCaps(hdc,0x5a);

        if (iVar2 == 0) {

          iVar2 = 0x48;

        }

        local_res8[0] = (undefined2)((local_60 * -0x48) / iVar2);

        ReleaseDC((HWND)0x0,hdc);

        cVar1 = FUN_14021f290(lVar3,local_res8,2);

        if (cVar1 != '\0') {

          local_res8[0] = local_50;

          cVar1 = FUN_14021f290(lVar3,local_res8,2);

          if (cVar1 != '\0') {

            local_res8[0] = CONCAT11(local_res8[0]._1_1_,local_4c);

            cVar1 = FUN_14021f290(lVar3,local_res8,1);

            if (cVar1 != '\0') {

              local_res8[0] = CONCAT11(local_res8[0]._1_1_,local_49);

              cVar1 = FUN_14021f290(lVar3,local_res8,1);

              if ((cVar1 != '\0') && (cVar1 = FUN_14021f3b0(lVar3,local_44), cVar1 != '\0')) {

                return lVar3;

              }

            }

          }

        }

      }

    }

    FUN_14021f870(lVar3);

  }

  return 0;

}




