let _ = {
  open Jest;
  open Pouchdb;
  let dbUrl = "http://localhost:5984/testdb";
  let db = ref(pouchdb(dbUrl));
  let recreateDb = () =>
    Js.Promise.(
      destroy(db^)
      |> then_(() => resolve(pouchdb(dbUrl)))
      |> then_(newDb => {
           db := newDb;
           resolve();
         })
    );
  describe("PouchDB", () =>
    beforeAllPromise(() => recreateDb())
  );
};
/* describe("when getting database info", () => */
/*   testAsync("it should return the database name", finish => { */
/*     let db = pouchdb(dbUrl); */
/*     db */
/*     |> PouchDBConnection.info */
/*     |> Js.Promise.then_((info: DatabaseInfo.t) => { */
/*          let assertion = expect(info##db_name) |> toEqual("testdb"); */
/*          finish(assertion); */
/*          Js.Promise.resolve(); */
/*        }) */
/*     |> ignore; */
/*     db |> PouchDBConnection.closeConnection |> ignore; */
/*   }) */
/* ); */
/* describe("when posting an item into the database", () => */
/*   testAsync("it should create the record and return a new id", finish => { */
/*     let db = pouchdb(dbUrl); */
/*     db */
/*     |> PouchDBConnection.post({"name": "byron"}) */
/*     |> Js.Promise.then_((response: RevResponse.t) => { */
/*          expect(response##ok) |> toBe(true) |> ignore; */
/*          finish(expect(response##id |> String.length) |> toBeGreaterThan(31)); */
/*          Js.Promise.resolve(); */
/*        }) */
/*     |> ignore; */
/*     db |> PouchDBConnection.closeConnection |> ignore; */
/*   }) */
/* ); */
/* describe("when upserting a new item in the database", () => */
/*   testAsync("it should modify the record and return a new rev", finish => { */
/*     let id = "upsert_new_test" ++ string_of_float(Js.Date.now()); */
/*     let db = pouchdb(dbUrl); */
/*     db */
/*     |> PouchDBConnection.put({"_id": id, "name": "byron"}) */
/*     |> Js.Promise.then_((response: RevResponse.t) => { */
/*          expect(response##ok) |> toBe(true) |> ignore; */
/*          finish(expect(response##id) |> toEqual(id)); */
/*          Js.Promise.resolve(); */
/*        }) */
/*     |> ignore; */
/*     db |> PouchDBConnection.closeConnection |> ignore; */
/*   }) */
/* ); */
/* describe("when upserting an existing item in the database", () => */
/*   testAsync("it should modify the record and return a new rev", finish => { */
/*     let id = "upsert_existing_test" ++ string_of_float(Js.Date.now()); */
/*     let db = pouchdb(dbUrl); */
/*     db */
/*     |> PouchDBConnection.put({"_id": id, "name": "byron"}) */
/*     |> Js.Promise.then_((response: RevResponse.t) => { */
/*          let rev = response##rev; */
/*          db */
/*          |> PouchDBConnection.put({ */
/*               "_id": id, */
/*               "name": "george", */
/*               "_rev": rev, */
/*             }) */
/*          |> Js.Promise.then_((response: RevResponse.t) => { */
/*               finish(expect(response##rev) |> not_ |> toEqual(rev)); */
/*               db |> PouchDBConnection.closeConnection |> ignore; */
/*               Js.Promise.resolve(); */
/*             }) */
/*          |> ignore; */
/*          Js.Promise.resolve(); */
/*        }) */
/*     |> ignore; */
/*     (); */
/*   }) */
/* ); */
/* describe("when deleting an existing item from the database", () => */
/*   testAsync("it should mark the item as deleted return a new rev", finish => { */
/*     let db = pouchdb(dbUrl); */
/*     db */
/*     |> PouchDBConnection.post({"name": "byron"}) */
/*     |> Js.Promise.then_((created: RevResponse.t) => { */
/*          db */
/*          |> PouchDBConnection.remove({ */
/*               "_id": created##id, */
/*               "_rev": created##rev, */
/*             }) */
/*          |> Js.Promise.then_((removed: RevResponse.t) => { */
/*               finish( */
/*                 expect(removed##rev) |> not_ |> toEqual(created##rev), */
/*               ); */
/*               db |> PouchDBConnection.closeConnection |> ignore; */
/*               Js.Promise.resolve(); */
/*             }) */
/*          |> ignore; */
/*          Js.Promise.resolve(); */
/*        }) */
/*     |> ignore; */
/*     (); */
/*   }) */
/* ); */
/* describe("when fetching an existing item from the database", () => */
/*   testAsync("it should retrieve the correct item", finish => { */
/*     let db = pouchdb(dbUrl); */
/*     db */
/*     |> PouchDBConnection.post({"name": "byron"}) */
/*     |> Js.Promise.then_((created: RevResponse.t) => { */
/*          db */
/*          |> PouchDBConnection.get(created##id) */
/*          |> Js.Promise.then_(fetched => { */
/*               finish(expect(fetched##name) |> toEqual("byron")); */
/*               db |> PouchDBConnection.closeConnection |> ignore; */
/*               Js.Promise.resolve(); */
/*             }) */
/*          |> ignore; */
/*          Js.Promise.resolve(); */
/*        }) */
/*     |> ignore; */
/*     (); */
/*   }) */
/* ); */
/* describe("when querying for existing items in the database", () => */
/*   testAsync("it should retrieve the correct items", finish => { */
/*     let db = pouchdb(dbUrl); */
/*     let name = string_of_float(Js.Date.now()); */
/*     db */
/*     |> PouchDBConnection.post({"name": name}) */
/*     |> Js.Promise.then_((created: RevResponse.t) => { */
/*          expect(created##ok) |> toBeTruthy |> ignore; */
/*          let rev = created##rev; */
/*          db */
/*          |> PouchDBConnection.find( */
/*               FindRequest.query(~selector={"name": name}, ()), */
/*             ) */
/*          |> Js.Promise.then_(response => { */
/*               let docs = response##docs; */
/*               expect(docs[0]##_rev) |> toEqual(rev) |> ignore; */
/*               finish(expect(docs[0]##name) |> toEqual()); */
/*               db |> PouchDBConnection.closeConnection |> ignore; */
/*               Js.Promise.resolve(); */
/*             }) */
/*          |> Js.Promise.catch(err */
/*               /\* finish(expect(err##error) |> toEqual("")); *\/ */
/*               => Js.Promise.resolve(Js.log(err))) */
/*          |> ignore; */
/*          Js.Promise.resolve(); */
/*        }) */
/*     |> ignore; */
/*     (); */
/*   }) */
/* ); */
