from iterm2.preferences import PreferenceKey

def test_deprecated_dup_pref():
    names = [x.name for x in PreferenceKey]
    assert "SIZE_CHANGES_AFFECT_PROFILE" not in names
    assert "TEXT_SIZE_CHANGES_AFFECT_PROFILE" in names
