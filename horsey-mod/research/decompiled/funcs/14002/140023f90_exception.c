// Address: 0x140023f90
// Ghidra name: exception
// ============ 0x140023f90 exception (size=50) ============


/* Library Function - Single Match

    public: __cdecl std::exception::exception(class std::exception const & __ptr64) __ptr64

   

   Library: Visual Studio 2019 Release */



exception * __thiscall std::exception::exception(exception *this,exception *param_1)



{

  *(undefined ***)this = vftable;

  *(undefined8 *)(this + 8) = 0;

  *(undefined8 *)(this + 0x10) = 0;

  FUN_1402c8190(param_1 + 8);

  return this;

}




