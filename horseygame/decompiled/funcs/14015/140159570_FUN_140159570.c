// Address: 0x140159570
// Ghidra name: FUN_140159570
// ============ 0x140159570 FUN_140159570 (size=36) ============


ulonglong FUN_140159570(short param_1,short param_2)



{

  ulonglong uVar1;

  

  uVar1 = 0x57e;

  if ((param_1 == 0x57e) &&

     ((uVar1 = 0x2008, param_2 == 0x2008 || (uVar1 = 0x2068, param_2 == 0x2068)))) {

    return CONCAT71((int7)(uVar1 >> 8),1);

  }

  return uVar1 & 0xffffffffffffff00;

}




