// Address: 0x14022cbd0
// Ghidra name: FUN_14022cbd0
// ============ 0x14022cbd0 FUN_14022cbd0 (size=232) ============


void FUN_14022cbd0(longlong param_1,char param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  BOOL BVar3;

  int iVar4;

  LPCWSTR pwszDriver;

  HDC hdc;

  DWORD local_res8 [2];

  WCHAR local_218 [264];

  

  lVar1 = *(longlong *)(param_1 + 0x188);

  pwszDriver = (LPCWSTR)FUN_14016d3b0();

  if ((pwszDriver != (LPCWSTR)0x0) &&

     (hdc = CreateDCW(pwszDriver,(LPCWSTR)0x0,(LPCWSTR)0x0,(DEVMODEW *)0x0), hdc != (HDC)0x0)) {

    local_res8[0] = 0x104;

    BVar3 = GetICMProfileW(hdc,local_res8,local_218);

    if ((BVar3 != 0) &&

       ((*(longlong *)(lVar1 + 0xb0) == 0 ||

        (iVar4 = FUN_14012fbc0(*(longlong *)(lVar1 + 0xb0),local_218), iVar4 != 0)))) {

      FUN_1401841e0(*(undefined8 *)(lVar1 + 0xb0));

      uVar2 = FUN_14012fc00(local_218);

      *(undefined8 *)(lVar1 + 0xb0) = uVar2;

      if (param_2 != '\0') {

        FUN_1401cda90(param_1,0x212,0,0);

      }

    }

    DeleteDC(hdc);

  }

  return;

}




