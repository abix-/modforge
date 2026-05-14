// Address: 0x1401842c0
// Ghidra name: FUN_1401842c0
// ============ 0x1401842c0 FUN_1401842c0 (size=85) ============


HANDLE FUN_1401842c0(void)



{

  HANDLE pvVar1;

  

  pvVar1 = (HANDLE)FUN_1401638b0(&DAT_1403fcb20);

  if ((pvVar1 == (HANDLE)0x0) &&

     (pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0), pvVar1 != (HANDLE)0x0)) {

    FUN_140163ac0(&DAT_1403fcb20,pvVar1,&DAT_140184270);

  }

  return pvVar1;

}




