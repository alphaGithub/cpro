namespace gate {
class and_gate{
    public:
    char input(char,char);
    char input(char *);
    char * input(char *,char *);
};
class nand_gate{
    public:
    char input(char,char);
    char input(char *);
    char * input(char *,char *);
};
class or_gate{
    public:
    char input(char,char);
    char input(char *);
    char * input(char *,char *);
};
class nor_gate{
    public:
    char input(char,char);
    char input(char *);
    char * input(char *,char *);
};
class not_gate{
    public:
    char input(char);
    char * input(char *);
};
class xor_gate{
    public:
    char input(char,char);
    char * input(char *,char *);
};
class xnor_gate{
    public:
    char input(char,char);
    char * input(char *,char *);
};
class full_adder{
    private:
    char sum(char,char,char);
    char carry(char,char,char);
    public:
    char * add(char*,char*,char);
};
class mux{
    public:
    char select(char *,char *);
};
}

