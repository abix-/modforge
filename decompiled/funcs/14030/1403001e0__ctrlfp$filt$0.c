// Address: 0x1403001e0
// Ghidra name: _ctrlfp$filt$0
// ============ 0x1403001e0 _ctrlfp$filt$0 (size=45) ============


/* Library Function - Single Match

    _ctrlfp$filt$0

   

   Library: Visual Studio 2005 Release */



undefined8 _ctrlfp_filt_0(undefined8 *param_1)



{

  undefined8 uVar1;

  

  if ((*(int *)*param_1 == -0x3ffffffb) || (*(int *)*param_1 == -0x3fffffe3)) {

    uVar1 = 1;

  }

  else {

    uVar1 = 0;

  }

  return uVar1;

}




