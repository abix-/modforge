// Address: 0x140209ec0
// Ghidra name: FUN_140209ec0
// ============ 0x140209ec0 FUN_140209ec0 (size=153) ============


void FUN_140209ec0(void)



{

  UINT UVar1;

  PRAWINPUTDEVICELIST pRawInputDeviceList;

  uint uVar2;

  uint local_res8 [2];

  

  uVar2 = 0;

  local_res8[0] = 0;

  UVar1 = GetRawInputDeviceList((PRAWINPUTDEVICELIST)0x0,local_res8,0x10);

  if (((UVar1 != 0xffffffff) && (local_res8[0] != 0)) &&

     (pRawInputDeviceList = (PRAWINPUTDEVICELIST)FUN_1401841f0((ulonglong)local_res8[0] << 4),

     pRawInputDeviceList != (PRAWINPUTDEVICELIST)0x0)) {

    local_res8[0] = GetRawInputDeviceList(pRawInputDeviceList,local_res8,0x10);

    if ((local_res8[0] != 0xffffffff) && (local_res8[0] != 0)) {

      do {

        FUN_140209a70(pRawInputDeviceList[uVar2].hDevice);

        uVar2 = uVar2 + 1;

      } while (uVar2 < local_res8[0]);

    }

    FUN_1401841e0(pRawInputDeviceList);

  }

  return;

}




