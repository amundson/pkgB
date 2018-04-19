#ifndef PKGB_H_

class PkgB
{
  private:
    bool just_used;

  public:
    PkgB(bool just_used);
    int doit() const;
};

#endif // PKGB_H_
